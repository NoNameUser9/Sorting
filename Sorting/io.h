#pragma once
#include <string>
#include <chrono>
#include "struct.h"

class address;
void read_vec(dualtype& vec, const address& path);
void write_vec(const dualtype& vec, const address& path);
void write_vec_sort_time(dualtype& vec, const uint64_t& col, sort_type& type_name, const std::chrono::duration<double>& time);
// using namespace std;  // NOLINT(clang-diagnostic-header-hygiene)

/**
 * \param a a[] array
 * \param col is column of sort
 */
void print(const dualtype* a, uint64_t& col);

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