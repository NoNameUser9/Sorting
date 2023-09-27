#pragma once
#include <string>

typedef std::byte path_mode;
typedef std::byte wr_mode;

// ReSharper disable once IdentifierTypo
struct dualtype
{
    // ReSharper disable CppInconsistentNaming
    int* Int{};
    std::string* Str{};
    mutable bool is_Str = false;
    mutable bool is_Str_read = false;
    // ReSharper restore CppInconsistentNaming
};