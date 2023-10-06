// #pragma comment(lib, "<C:\Users\User\Documents\new\lib\ExcelFormat.lib>")
#include "io.h"
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <vector>

// ReSharper disable once CppCompileTimeConstantCanBeReplacedWithBooleanConstant
void read_vec(dualtype& vec, const address& path)
{
    // ReSharper disable CommentTypo
    // std::setlocale(LC_ALL, "");

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
        
    for(int i = 0; getline(fin, line); ++i)
    {
        vec.Table.resize(i+1);
        int j = 0, jj = 0;
        for(auto itl = line.begin(); itl != line.end(); ++j, ++jj, ++itl)
        {
            std::string ts;
            for(auto ii = 0; !(itl == line.end() || line.at(jj) == ';'); ++ii, ++jj, ++itl)
                ts += line[jj];
                    
            vec.Table[i].resize(j+1);
            vec.Table[i][j] = ts;
            if(itl == line.end())
            {
                --jj; --itl;
            }
        }
    }
    fin.close();
}

void write_vec(const dualtype& vec, const address& path)
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
        // int a = vec.Table.size();
        for(uint64_t j = 0; j < i.size(); ++j)
        {
            if(i.size()-1 == j)
                str += i[j] + '\n';
            else
                str += i[j] + ';';
        }
        // str += '\n';
        fout_str.write(str.c_str(), static_cast<std::streamsize>(str.size()));
    }
    fout_str.close();
    // vec.is_Str_read = false;
    // return;
}

// void read(const dualtype& a, const address& path)
// {
//     std::setlocale(LC_ALL, "");
//
//     if(path.get_mode() != address::read)
//     {
//         std::cout << "\nthe file isn't opened to read(mod is not read)!\n";
//         return;
//     }
//     
//     std::string line;    
//     if(a.is_Str_read)
//     {
//         std::fstream fin((path.get_address_str()), std::fstream::in);
//         if(!fin.is_open())
//         {
//             std::cout << "\nthe file isn't opened to read(str)!\n";
//             return;
//         }
//         for(int i = 0; getline(fin, line); ++i)
//             a.Table[i] = line;
//         fin.close();
//         return;
//     }
//     
//     std::fstream fin(path.get_address(), std::fstream::in);
//     if(!fin.is_open())
//     {
//         std::cout << "\nthe file isn't opened(int)!\n";
//         return;
//     }
//
//     std::stringstream ss;
//     for(int i = 0; getline(fin, line); ++i)
//     {
//         ss.clear();
//         ss << line;
//         ss >> a.Table[i];
//     }
//     
//     fin.close();
// }
//
// void write(const dualtype& a, const address& path, const int num)
// {
//     if(path.get_mode() != address::write)
//     {
//         std::cout << "\nthe file isn't opened for write(mode is not write)!\n";
//         return;
//     }
//     
//     // ReSharper disable once IdentifierTypo
//     if(a.is_Str_read == true)
//     {
//         std::fstream fout_str(path.get_address_str(), std::fstream::trunc|std::fstream::out);
//         // ReSharper disable once IdentifierTypo
//         if(!fout_str.is_open())
//         {
//             std::cout << "the file isn't opened(str)!\n";
//             return;
//         }
//         for(int i = 0; i < num; ++i)
//         {
//             std::string str = a.Table[i] + '\n';
//             fout_str.write(str.c_str(), static_cast<std::streamsize>(str.size()));
//         }
//         fout_str.close();
//         a.is_Str_read = false;
//         return;
//     }
//     
//     // ReSharper disable once IdentifierTypo
//     std::fstream fout(path.get_address(), std::fstream::trunc|std::fstream::out);
//     if(!fout.is_open())
//     {
//         std::cout << "the file isn't opened(int)!\n";
//         fout.close();
//         return;
//     }
//     
//     for(int i = 0; i < num; ++i)
//     {
//         std::string str = std::to_string(a.Table[i]) + '\n';
//         fout.write(str.c_str(), static_cast<std::streamsize>(str.size()));
//     }
//     
//     fout.close();
// }
    // ReSharper restore CommentTypo

void print(const dualtype& a, const uint64_t& col)
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