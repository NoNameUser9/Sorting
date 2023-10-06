#pragma once
#include <string>
#include <vector>

typedef std::byte path_mode;
typedef std::byte wr_mode;

// ReSharper disable once IdentifierTypo
// ReSharper disable CppInconsistentNaming
struct dualtype
{
    std::vector<std::vector<std::string>> Table;
    mutable bool is_Str = false;
    mutable bool is_Str_read = false;
    // ReSharper restore CppInconsistentNaming
};
