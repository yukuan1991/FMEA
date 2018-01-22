#include "des.h"
#include <string>
#include <cstring>
#include <stdlib.h>
#include <cstdio>
#include <memory>
#include "encryption.h"
#include <iso646.h>


int krys3des_raw_encryption (const void* src, int input_length, void* key24bytes, void* out_buffer)
{
    if (src == nullptr or input_length <= 0 or key24bytes == nullptr or out_buffer == nullptr)
    {
        errno = EINVAL;
        return -1;
    }

    /*------------------------------generating des3 context--------------------------------------------*/
    des3_context context;
    int des3_length;
    /*-------------------------------------------------------------------------------------------------*/


    /*-------------------------------------------init data---------------------------------------------*/
    des3_set_3keys (&context, (unsigned char*)key24bytes);
    des3_length = input_length + (8 - input_length % 8);
    auto source_3des = std::make_unique<char[]> (des3_length);		/*des3 formatted input*/
    /*----------------------------------------------END------------------------------------------------*/


    /*--------------------------------------------encryption-------------------------------------------*/
    memcpy (source_3des.get(), src, input_length);
    memset (source_3des.get() + input_length, des3_length - input_length, des3_length - input_length);

    for (int i = 0; i < des3_length; i += 8)
    {
        des3_encrypt (&context, (unsigned char*)source_3des.get () + i, (unsigned char*)out_buffer + i);
    }
    /*----------------------------------------------END------------------------------------------------*/

    return des3_length;
}


/*
 *	out_buffer's length must be the same as the input buffer (aka src)
 */

int krys3des_raw_decryption (const void* src, unsigned int input_length, void* key24bytes, void*out_buffer)
{
    if (src == nullptr  or input_length == 0 or input_length % 8 != 0
            or key24bytes == nullptr or out_buffer == nullptr)
    {
        errno = EINVAL;
        return -1;
    }

    des3_context context;
    des3_set_3keys (&context, (const unsigned char*)key24bytes);

    for (unsigned int i = 0; i < input_length; i += 8)
    {
        des3_decrypt (&context, (unsigned char*)src + i, (unsigned char*)out_buffer + i);
    }

    if (((unsigned char*)out_buffer)[input_length - 1] < 1 or ((unsigned char*)out_buffer)[input_length - 1] > 8)
    {
        errno = EINVAL;
        return -1;
    }

    for (char* p = &((char*)out_buffer)[input_length - 1];
            p > &((char*)out_buffer)[input_length - 1 - ((char*)out_buffer)[input_length - 1] ]; p--)
    {
        if (*p != ((char*)out_buffer)[input_length - 1])
        {
            errno = EINVAL;
            return -1;
        }
    }


    return input_length - ((unsigned char*)out_buffer)[input_length - 1];
}




void krys3des_decryption (const std::string & input, const char* key24bytes, std::string & output)
{

    /*--------------------------------------------init data--------------------------------------------*/
    des3_context context;
    des3_set_3keys (&context, (const unsigned char*)key24bytes);
    int length = input.length()/2;

    char tmp[3];
    tmp[2] = 0;

    auto source_3des = std::make_unique<char[]>(length);
    auto output_3des = std::make_unique<char[]>(length);
    output.resize (length);
    /*----------------------------------------------END------------------------------------------------*/



    /*------------------------------------------length examine-----------------------------------------*/
    if (length % 8 != 0 or length == 0)
    {
        output.clear();
        return;
    }
    /*----------------------------------------------END------------------------------------------------*/


    /*---------------------------------hex to bytestream converting------------------------------------*/
    for (unsigned long i=0; i<input.size()/2; i++)
    {
        strncpy (tmp, input.c_str() + 2 * i, 2);
        sscanf (tmp, "%hhx", source_3des.get() + i);
    }
    /*----------------------------------------------END------------------------------------------------*/


    /*-------------------------------------------decryption loop---------------------------------------*/
    for (int i = 0; i < length; i += 8)
    {
        //des3_decrypt (&context, (unsigned char*)source_3des.get() + i, (unsigned char*)output_3des.get() + i);
        des3_decrypt (&context, (unsigned char*)source_3des.get () + i, (unsigned char*)output.data () + i);
    }
    /*----------------------------------------------END------------------------------------------------*/

    /*-----------------------------------------validating result---------------------------------------*/
    if (output[length - 1] < 1 or output[length - 1] > 8)
    {
        output.clear ();
        return;
    }

    for (const char* p = output.data () + length - 1; p > output.data () + length - 1 - output[length - 1]; p--)
    {
        if (*p != output[length - 1])
        {
            output.clear ();
            return;
        }
    }
    output.resize (length - output[length - 1]);
    /*----------------------------------------------END------------------------------------------------*/
}


void krys3des_encryption (const std::string & source, const char* key24bytes, std::string & output)
{
    if (key24bytes == nullptr)
    {
        errno = EINVAL;
        output.clear();
        return;
    }

    /*------------------------------generating des3 context--------------------------------------------*/
    des3_context context;
    int input_length;
    int des3_length;
    /*-------------------------------------------------------------------------------------------------*/

    /*-------------------------------------------init data---------------------------------------------*/
    des3_set_3keys (&context, (unsigned char*)key24bytes);
    input_length = source.length();
    des3_length = input_length + (8 - input_length % 8);

    char hexbyte[3];  /*hex temp*/
    output.clear();

    auto source_3des = std::make_unique<char[]> (des3_length);		/*des3 formatted input*/
    auto output_3des = std::make_unique<char[]> (des3_length);		/*des3 formatted output*/
    /*----------------------------------------------END------------------------------------------------*/



    /*-----------------------------------set memory with fixed length----------------------------------*/
    memcpy (source_3des.get(), source.c_str(), input_length);
    memset (source_3des.get() + input_length, des3_length - input_length, des3_length - input_length);
    /*----------------------------------------------END------------------------------------------------*/


    /*-------------------------------------encryption blockwise----------------------------------------*/
    for (int i = 0; i < des3_length; i += 8)
    {
        des3_encrypt (&context, (unsigned char*)source_3des.get () + i, (unsigned char*)output_3des.get() + i);
    }
    /*----------------------------------------------END------------------------------------------------*/


    /*--------------------------------------------hex output-------------------------------------------*/
    for (int i = 0; i < des3_length; i++)
    {
        sprintf (hexbyte, "%02hhx", (unsigned char)output_3des[i]);
        output += hexbyte;
    }
    /*----------------------------------------------END------------------------------------------------*/

}

void percent_code (const char* input, int len, std::string& output, bool capital)
{
    output.resize (len * 3);
    int _3_X_I;

    for (int i = 0; i < len; i ++)
    {
        _3_X_I = 3 * i;
        output[_3_X_I] = '%';
        output [_3_X_I + 1] = (unsigned char)input[i] / 16;
        output [_3_X_I + 2] = (unsigned char)input[i] % 16;

        output[_3_X_I + 1] += (output[_3_X_I + 1] < 10 ? '0' : capital ? '7' : 'W');
        output[_3_X_I + 2] += (output[_3_X_I + 2] < 10 ? '0' : capital ? '7' : 'W');
    }
}

int gbk_len (const std::string& gbk)
{
    int len = 0;
    for (unsigned int i = 0; i < gbk.length(); i++)
    {
        len ++;
        if ((unsigned char)gbk[i] > 0x80)
        {
            i++;
        }
    }

    return len;
}
