#pragma once
#include <sstream>
#include <string>
#include <vector>

typedef std::byte path_mode;
typedef std::byte wr_mode;
typedef std::byte read_mode;

// ReSharper disable once IdentifierTypo
// ReSharper disable CppInconsistentNaming
struct unitype
{
    std::vector<std::vector<std::string>> Table;
    // mutable bool is_Date = false;
    bool str_or_int = false;
    mutable bool is_Str_read = false;
    void set_type_ft(const uint16_t& from, const uint16_t& to, const read_mode type = type_str|type_double|type_date)
    {
        for(uint16_t i = from; i <= to; ++i)
            set_type(i, type);
    }
    void set_type(const uint16_t& n, const read_mode type = type_str|type_double|type_date)
    {
        if(type == type_str)
        {
            type_str_ |= static_cast<uint32_t>(1 << n);
            type_double_ &= ~static_cast<uint32_t>(1 << n);
            type_date_ &= ~static_cast<uint32_t>(1 << n);
        }
        else if(type == type_double)
        {
            type_str_ &= ~static_cast<uint32_t>(1 << n);
            type_double_ |= static_cast<uint32_t>(1 << n);
            type_date_ &= ~static_cast<uint32_t>(1 << n);
        }
        else if(type == type_date)
        {
            type_str_ &= ~static_cast<uint32_t>(1 << n);
            type_double_ &= ~static_cast<uint32_t>(1 << n);
            type_date_ |= static_cast<uint32_t>(1 << n);
        }
    }

    read_mode get_type(const uint16_t& n) const
    {
        if(type_str_ & static_cast<uint32_t>(1 << n))
            return type_str;
        if(type_double_ & static_cast<uint32_t>(1 << n))
            return type_double;
        if(type_date_ & static_cast<uint32_t>(1 << n))
            return type_date;
        return {};
    }
    static constexpr read_mode type_str = static_cast<read_mode>(1 << 0);
    static constexpr read_mode type_double = static_cast<read_mode>(1 << 1);
    static constexpr read_mode type_date = static_cast<read_mode>(1 << 2);
private:
    uint32_t type_str_ = 1 << 0;
    uint32_t type_double_ = 0;
    uint32_t type_date_ = 0;
    // ReSharper restore CppInconsistentNaming
};

struct date
{
    void set_date(const std::string& date)
    {
        auto temp(date);
        std::stringstream ss;
        ss << date;
        std::getline(ss,temp,'.');
        day_ = temp;
        std::getline(ss,temp,'.');
        month_ = temp;
        std::getline(ss,temp,'.');
        year_ = temp;
    }

    [[nodiscard]] std::string to_str() const
    {
        return year_ + month_ + day_;
    }
private:
    std::string day_;
    std::string month_;
    std::string year_;
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
