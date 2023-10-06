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
    // mutable bool is_Str = false;
    mutable bool is_Str_read = false;
    bool str_or_int = false;
    // ReSharper restore CppInconsistentNaming
};

struct sort_type
{
    // ReSharper disable StringLiteralTypo
    inline static std::string bubble = "Пузырьковая";
    inline static std::string selection = "Выбором";
    inline static std::string insertion = "Вставками";
    inline static std::string q_sort = "Быстрая";
    inline static std::string merge = "Слиянием";
    inline static std::string shell = "Шелла";
    inline static std::string heap = "Кучей";
    inline static std::string literal = "Лексикографическая";
    // ReSharper restore StringLiteralTypo
    std::string get_name()
    {
        return name_;
    }
    void set_name(const std::string& name)
    {
        name_ = name;
    }

private:
    std::string name_;
};
