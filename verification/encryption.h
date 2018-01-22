/**
 * \file encryption.h
 */
#ifndef CIPHER_H
#define CIPHER_H

#include <string>
#include <iostream>



#define is_base64(character) \
    (((character) >= '/' and (character) <= '9') or \
     ((character) >= 'a' and (character) <= 'z') or \
     ((character) >= 'A' and (character) <= 'Z') or\
     ((character) == '+'))



void percent_code (const char* input, int len, std::string& output, bool capital = true);
int gbk_len (const std::string& gbk);

#ifdef __cplusplus
extern "C" {
#endif


/*----------------------------------function definitions-------------------------------------------*/


/**
 *encrypt a string type with 3des algorithm, with hex ouput format
 * \returns void
 */
void krys3des_encryption (const std::string & source, /**< [in] source string */
        const char* key24bytes, /**< [in] a pointer to the key buffer with the length of 24bytes */
        std::string & output/**< [out] docs for input parameter v. */
        );






/**
 *decrypt a given string with given key, the input string must be in hex format
 *\return void
 */
void krys3des_decryption (const std::string & input, /**< [in] encrypted string */
        const char* key24bytes, /**< [in] 3des key for decryption */
        std::string & output /**< [out] decrypted output string (empty string on failure) */
        );

int krys3des_raw_encryption (const void* src, int input_length, void* key24bytes, void* out_buffer);
int krys3des_raw_decryption (const void* src, unsigned int input_length, void* key24bytes, void*out_buffer);

/*----------------------------------------------END------------------------------------------------*/



#ifdef __cplusplus
}
#endif



#endif /*CIPHER_H*/
/*
 * \brief          Checkup routine
 *
 * \return         0 if successful, or 1 if the test failed
 */
