#include <boost/process.hpp>
#include "verification.h"
#include <QMessageBox>
#include "encryption.h"
#include <QDebug>
#include <memory>
#include <string_view>
#include <windows.h>
#include <boost/locale.hpp>
#include <string_view>
#include <QString>
#include <QDateTime>
#include <exception>
#include <base/io/file/file.hpp>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include <QApplication>
#include <base/utils/charset.hpp>
#include "../json.hpp"

#define SERIAL_PATH "serial"
#define DES_KEY "1234556789012345672IETools"
#define UPDATE_SERVER_ADDR "116.62.10.199"

using json = nlohmann::json;

using std::make_unique;
using std::string;
using std::string_view;

static std::string get_serial();

static bool local_verification(string_view serial, json data) noexcept;

bool verification_process()
{
    auto serial = get_serial();
    std::cout << serial << std::endl;
    auto op_str = file::read_all(SERIAL_PATH);
    if(op_str)
    {
      string output;
      krys3des_decryption(op_str.value(), DES_KEY, output);

      json data;
      try
      {
          data = json::parse(output);
      }
      catch(const std::exception &)
      {
          return false;
      }

      if(local_verification(serial, std::move(data)))
      {
          return true;
      }

    }

    return false;

}

/*获取硬盘序列号*/
static std::string get_serial()
{
    const char* lpRootPathName = "c:\\"; //取C盘

    auto lpVolumeNameBuffer = make_unique<char[]> (12);
    uint64_t nVolumeNameSize = 12; //卷标的字符串长度

    DWORD VolumeSerialNumber;
    unsigned long MaximumComponentLength; //最大的文件长度

    auto lpFileSystemNameBuffer = make_unique<char[]> (10);
    DWORD nFileSystemNameSize = 10; //分区类型的长指针变量所指向的字符串长度

    DWORD FileSystemFlags; //文件系统的一此标志
    ::GetVolumeInformationA(lpRootPathName,
                            lpVolumeNameBuffer.get(), nVolumeNameSize,
                            &VolumeSerialNumber, &MaximumComponentLength,
                            &FileSystemFlags,
                            lpFileSystemNameBuffer.get(), nFileSystemNameSize);
    uint32_t serial_number = static_cast<uint32_t> (VolumeSerialNumber);
    return std::to_string(serial_number);
}

static bool local_verification(string_view serial, json data) noexcept
try
{
    const string history_serial = data["serial"];
    const string last_datetime = data["last_datetime"];
    const string expire_date = data["expire_date"];
    const string account = data["account"];

    std::cout << history_serial << std::endl;
    std::cout << last_datetime << std::endl;
    std::cout << expire_date << std::endl;
    std::cout << account << std::endl;

    const auto last = QDateTime::fromString(last_datetime.data(), "yyyy-MM-dd hh:mm:ss");
    const auto expire = QDateTime::fromString(expire_date.data(), "yyyy-MM-dd hh:mm:ss");
    auto current = QDateTime::currentDateTime();
    if(last > current)
    {
        return false;
    }

    if(current > expire)
    {
        QMessageBox::information(NULL, "认证", "帐号已经过期");
        return false;
    }

    if(serial != history_serial)
    {
        return false;
    }

    return true;
}
catch(const std::exception &)
{
    return false;
}

void check_date ()
try
{
    auto op_str = file::read_all (SERIAL_PATH);
    if (!op_str)
    {
        QMessageBox::information (nullptr, "序列号", "序列号文件已经损坏，程序即将退出");
        boost::filesystem::remove (SERIAL_PATH);
        QApplication::instance ()->exit ();
        return;
    }

    string output;
    krys3des_decryption (op_str.value (), DES_KEY, output);
    auto data = json::parse (output);

    string time_str = data ["last_datetime"];
    const auto now = QDateTime::currentDateTime ();
    const auto then = QDateTime::fromString (time_str.data (), "yyyy-MM-dd hh:mm:ss");

    if (then > now)
    {
        QMessageBox::information (nullptr, "序列号", "检测到系统时间已经被修改，需要从新验证");
        boost::filesystem::remove (SERIAL_PATH);
        QApplication::instance ()->exit ();
        return;
    }

    data ["last_datetime"] = now.toString ("yyyy-MM-dd hh:mm:ss").toStdString ();
    string encrypted;
    krys3des_encryption (data.dump (), DES_KEY, encrypted);
    file::write_buffer (SERIAL_PATH, encrypted);
}
catch (const std::exception & )
{
    return;
}




