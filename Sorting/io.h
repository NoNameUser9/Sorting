﻿#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include "struct.h"
class address;
void read_vec(std::vector<std::vector<std::string>>& vec, const address& path);
void write_vec(std::vector<std::vector<std::string>>& vec, const address& path);
// using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

/**
 * \brief read data from file
 * \param a a[] array
 * \param path path to file with data
 */
// void read(const dualtype& a, const address& path);
/**
 * \brief write data to file (without _Str)
 * \param a a[] array
 * \param path path to file with data
 * \param num size of array
 */
void write(const dualtype& a, const address& path, int num);
void print(const dualtype* a, int num);

/**
 * \brief type of data which contains address of file with data
 */
class address  // NOLINT(cppcoreguidelines-special-member-functions)
{
public:
 address();
 // ReSharper disable CppInconsistentNaming
 explicit address(wr_mode WR_mode);
 explicit address(const std::string& path);
 
 address(const std::string& path, wr_mode WR_mode);
 address(const std::string& path, path_mode _Mode, wr_mode WR_mode);  // NOLINT(bugprone-reserved-identifier)
 void set_address(const std::string& path, path_mode _Mode, wr_mode WR_mode);  // NOLINT(bugprone-reserved-identifier)
 void set_address_str(const std::string& path);  // NOLINT(bugprone-reserved-identifier)
 // ReSharper restore CppInconsistentNaming

 [[nodiscard]] std::string get_address() const;
 [[nodiscard]] std::string get_address_str() const;
 [[nodiscard]] std::string get_path_mode() const;
 [[nodiscard]] wr_mode get_mode() const;
 [[nodiscard]] bool try_open() const;

 address& operator=(const address& right);
    
 static constexpr path_mode relative = static_cast<path_mode>(0);
 static constexpr path_mode absolute = static_cast<path_mode>(1);
 static constexpr wr_mode read = static_cast<wr_mode>(0);
 static constexpr wr_mode write = static_cast<wr_mode>(1);
private:
 path_mode path_mode_;
 wr_mode wr_mode_;
 std::string path_;
 std::string path_str_;
};