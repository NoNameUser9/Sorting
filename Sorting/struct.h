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
    bool is_Int = false;
    bool is_Str = false;
    // ReSharper restore CppInconsistentNaming
};