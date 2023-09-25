#pragma once
#include <string>

#include "struct.h"
class address;
using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)
typedef byte mode;
typedef byte wr_mode;

/**
 * \brief read data from file
 * \param a a[] array
 * \param path path to file with data
 * \param type type of data
 */
void read(const my_struct& a, const address& path, std::underlying_type_t<std::byte> type);
/**
 * \brief write data to file (without _Str)
 * \param a a[] array
 * \param path path to file with data
 * \param num size of array
 * \param type type of data
 */
void write(const my_struct& a, const address& path, int num, std::underlying_type_t<std::byte> type);
void print(const int* a, int num);
class address  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
 address();
 // ReSharper disable once CppInconsistentNaming
 explicit address(wr_mode WR_mode);
 address(const string& path, wr_mode WR_mode);
 explicit address(const string& path);
 
 // ReSharper disable CppInconsistentNaming
 void set_address(const string& path, mode _Mode, wr_mode WR_mode);  // NOLINT(bugprone-reserved-identifier)
 // ReSharper restore CppInconsistentNaming

 [[nodiscard]] string get_address() const;
 [[nodiscard]] string get_mode() const;
 [[nodiscard]] bool try_open() const;

 address& operator=(const address& right);
    
 static constexpr mode relative = static_cast<mode>(0);
 static constexpr mode absolute = static_cast<mode>(1);
 static constexpr wr_mode write = static_cast<wr_mode>(0);
 static constexpr wr_mode read = static_cast<wr_mode>(1);
 static constexpr wr_mode custom = static_cast<wr_mode>(2);
private:
 const string write_ = "data_out.csv";
 const string read_ = "data.csv";
 const string custom_;
 string wr_;
 mode mode_;
 wr_mode wr_mode_;
 string path_;
};