// #pragma comment(lib, "<C:\Users\User\Documents\new\lib\ExcelFormat.lib>")
#include "io.h"
#include <iostream>
#include <fstream>
#include <sstream>

// ReSharper disable once CppCompileTimeConstantCanBeReplacedWithBooleanConstant
void read_vec(unitype& a, const address& path)
{
    // ReSharper disable CommentTypo
    if(path.get_mode() != address::read)
    {
        std::cout << "\nthe file isn't opened to read(mod is not read)!\n";
        return;
    }
    
    std::string line; 
    std::fstream fin((path.get_address()), std::fstream::in);
    if(!fin.is_open())
    {
        std::cout << "\nthe file isn't opened to read(str)!\n";
        return;
    }
        
    auto size = 0;
    for(int i = 0; getline(fin, line); ++i)
    {
        a.Table.resize(i+1);
        int j = 0, jj = 0;
        for(auto itl = line.begin(); itl != line.end(); ++j, ++jj, ++itl)
        {
            std::string ts;
            for(uint64_t ii = 0; !(itl == line.end() || line.at(jj) == ';'); ++ii, ++jj, ++itl)
                ts += line[jj];
            if(size < j)
                size = j+1;
            a.Table[i].resize(j+1);
            a.Table[i][j] = ts;
            if(itl == line.end())
            {
                --jj; --itl;
            }
        }
    }
    for (auto& i : a.Table)
        i.resize(size);
    fin.close();
}

void write_vec(const unitype& vec, const address& path)
{
    if(path.get_mode() != address::write)
    {
        std::cout << "\nthe file isn't opened for write(mode is not write)!\n";
        return;
    }
    
    // ReSharper disable once IdentifierTypo
    std::fstream fout_str(path.get_address(), std::fstream::trunc|std::fstream::out);
    // ReSharper disable once IdentifierTypo
    if(!fout_str.is_open())
    {
        std::cout << "the file isn't opened(str)!\n";
        return;
    }
    for (auto& i : vec.Table)
    {
        std::string str;
        for(uint64_t j = 0; j < i.size(); ++j)
        {
            if(i.size()-1 == j)
                str += i[j] + '\n';
            else
                str += i[j] + ';';
        }
        
        fout_str.write(str.c_str(), static_cast<std::streamsize>(str.size()));
    }
    
    fout_str.close();
}

void write_vec_sort_time(unitype& vec, const uint64_t& col, sort_type& type_name, const std::chrono::duration<double>& time)
{ 
    for (auto& i : vec.Table)
    {
        if(i[0] == type_name.get_name())
        {
            std::stringstream ss;
            ss << time.count();
            // std::string s;
            ss >> i[col];
            // i[col] = s;
            return;
        }
    }
}

// ReSharper restore CommentTypo
void print(const unitype& a, const uint64_t& col)
{
    for (const auto& i : a.Table)
        std::cout << i[col] << " ";
    
    std::cout << std::endl;
}

// ReSharper disable once CppPossiblyUninitializedMember
address::address()  // NOLINT(cppcoreguidelines-pro-type-member-init, modernize-use-equals-default)
{
    path_mode_ = relative;
    wr_mode_ = read;
    path_ = "~\\";
}

// ReSharper disable once CppInconsistentNaming
address::address(const wr_mode WR_mode = write|read)
{
    path_mode_ = relative;
    
    if(WR_mode == write)
    {
        wr_mode_ = write;
        path_ = "~\\";
    }
    else if(WR_mode == read)
    {
        wr_mode_ = read;
        path_ = "~\\";
    }
}

// ReSharper disable once CppPossiblyUninitializedMember
// ReSharper disable once CppInconsistentNaming
address::address(const std::string& path, const wr_mode WR_mode = write|read)  // NOLINT(cppcoreguidelines-pro-type-member-init)
{
    if(WR_mode == write)
    {
        wr_mode_ = write;
        path_ = path;
    }
    else if(WR_mode == read)
    {
        wr_mode_ = read;
        path_ = path;
    }

    path_mode_ = absolute;
}

// ReSharper disable CppInconsistentNaming
address::address(const std::string& path, const path_mode _Mode = relative|absolute, const wr_mode WR_mode = write|read)  // NOLINT(cppcoreguidelines-pro-type-member-init, clang-diagnostic-reserved-identifier, bugprone-reserved-identifier)
// ReSharper restore CppInconsistentNaming
{
    set_address(path, _Mode, WR_mode);
}

// ReSharper disable once CppPossiblyUninitializedMember
address::address(const std::string& path)  // NOLINT(cppcoreguidelines-pro-type-member-init)
{
    wr_mode_ = read;
    path_ = path;
    path_mode_ = absolute;
}

// ReSharper disable CppInconsistentNaming
// ReSharper disable once CppCompileTimeConstantCanBeReplacedWithBooleanConstant
void address::set_address(const std::string& path, const path_mode _Mode = relative|absolute, const wr_mode WR_mode = write|read)  // NOLINT(clang-diagnostic-reserved-identifier, bugprone-reserved-identifier)
// ReSharper restore CppInconsistentNaming
{
    if(WR_mode == write)
        wr_mode_ = write;
    else if(WR_mode == read)
        wr_mode_ = read;
    
    if(_Mode == relative)
    {
        path_ = "~\\" + path;
        path_mode_ = relative;
    }
    else if (_Mode == absolute)
    {
        path_ = path;  // NOLINT(bugprone-branch-clone)
        path_mode_ = absolute;
    }
    else
        std::cout << "wrong address::get_address _Mode";
}

void address::set_address_str(const std::string& path)
{
    path_str_ = path;
}

std::string address::get_address() const
{
    return path_;
}

std::string address::get_address_str() const
{
    return path_str_;
}

std::string address::get_path_mode() const
{
    std::string str;
    
    if(path_mode_ == relative)
        str = "relative";
    if(path_mode_ == absolute)
        str = "absolute";
    
    return str;
}

wr_mode address::get_mode() const
{
    return wr_mode_;
}

bool address::try_open() const
{
    if(const std::fstream fin(path_); fin.is_open())
        return true;

    std::cout << "file isn't opened(try_open())!\n";
    return false;
}

address& address::operator=(const address& right)
{
    this->path_ = right.path_;
    return *this;    
}