#pragma once
#include <string>
#include <vector>

typedef std::byte path_mode;
typedef std::byte wr_mode;

// ReSharper disable once IdentifierTypo
struct dualtype
{
    // ReSharper disable CppInconsistentNaming
    mutable std::vector<int> Int;
    mutable std::vector<std::string> Str;
    mutable bool is_Str = false;
    mutable bool is_Str_read = false;
    // ReSharper restore CppInconsistentNaming
};