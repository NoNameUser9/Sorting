#pragma once
#include <string>

struct my_struct
{
    std::string* str;
    int* Int;
};

enum my_enum : std::underlying_type_t<std::byte>
{
    _Int = 0,  // NOLINT(clang-diagnostic-reserved-identifier, bugprone-reserved-identifier)
    // ReSharper disable once CppInconsistentNaming
    _Str = 1  // NOLINT(bugprone-reserved-identifier, clang-diagnostic-reserved-identifier)
};