﻿#include "io.h"
#include <fstream>
#include <iostream>
#include <sstream>

// ReSharper disable once CppCompileTimeConstantCanBeReplacedWithBooleanConstant
void read(const dualtype& a, const address& path)
{
    if(path.get_mode() != address::read)
    {
        cout << "\nthe file isn't opened to read(mod is not read)!\n";
        return;
    }
    
    string line;
    if(a.is_Str_read)
    {
        fstream fin(path.get_address_str(), fstream::in);
        if(!fin.is_open())
        {
            cout << "\nthe file isn't opened to read(str)!\n";
            return;
        }
        for(int i = 0; getline(fin, line); ++i)
            a.Str[i] = line;
        fin.close();
        return;
    }
    
    fstream fin(path.get_address(), fstream::in);
    if(!fin.is_open())
    {
        cout << "\nthe file isn't opened(int)!\n";
        return;
    }
    
    stringstream ss;
    for(int i = 0; getline(fin, line); ++i)
    {
        ss.clear();
        ss << line;
        ss >> a.Int[i];
    }
    
    fin.close();
}

void write(const dualtype& a, const address& path, const int num)
{
    if(path.get_mode() != address::write)
    {
        cout << "\nthe file isn't opened for write(mode is not write)!\n";
        return;
    }
    
    // ReSharper disable once IdentifierTypo
    if(a.is_Str_read == true)
    {
        fstream fout_str(path.get_address_str(), fstream::trunc|fstream::out);
        // ReSharper disable once IdentifierTypo
        if(!fout_str.is_open())
        {
            cout << "the file isn't opened(str)!\n";
            return;
        }
        for(int i = 0; i < num; ++i)
        {
            string str = a.Str[i] + '\n';
            fout_str.write(str.c_str(), static_cast<streamsize>(str.size()));
        }
        fout_str.close();
        a.is_Str_read = false;
        return;
    }
    
    // ReSharper disable once IdentifierTypo
    fstream fout(path.get_address(), fstream::trunc|fstream::out);
    if(!fout.is_open())
    {
        cout << "the file isn't opened(int)!\n";
        fout.close();
        return;
    }
    
    for(int i = 0; i < num; ++i)
    {
        string str = to_string(a.Int[i]) + '\n';
        fout.write(str.c_str(), static_cast<streamsize>(str.size()));
    }
    
    fout.close();
}

void print(const dualtype& a, const int num)
{
    if(a.is_Str_read == false)
        for(int i = 0; i < num; i++)
            cout << a.Int[i] << " ";
    else
    {
        for(int i = 0; i < num; i++)
            cout << a.Str[i] << " ";
        a.is_Str_read = false;
    }
    
    cout << endl;
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
address::address(const string& path, const wr_mode WR_mode = write|read)  // NOLINT(cppcoreguidelines-pro-type-member-init)
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
address::address(const string& path, const path_mode _Mode = relative|absolute, const wr_mode WR_mode = write|read)  // NOLINT(cppcoreguidelines-pro-type-member-init, clang-diagnostic-reserved-identifier, bugprone-reserved-identifier)
// ReSharper restore CppInconsistentNaming
{
    set_address(path, _Mode, WR_mode);
}

// ReSharper disable once CppPossiblyUninitializedMember
address::address(const string& path)  // NOLINT(cppcoreguidelines-pro-type-member-init)
{
    wr_mode_ = read;
    path_ = path;
    path_mode_ = absolute;
}

// ReSharper disable CppInconsistentNaming
// ReSharper disable once CppCompileTimeConstantCanBeReplacedWithBooleanConstant
void address::set_address(const string& path, const path_mode _Mode = relative|absolute, const wr_mode WR_mode = write|read)  // NOLINT(clang-diagnostic-reserved-identifier, bugprone-reserved-identifier)
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
        cout << "wrong address::get_address _Mode";
}

void address::set_address_str(const string& path)
{
    path_str_ = path;
}

string address::get_address() const
{
    return path_;
}

string address::get_address_str() const
{
    return path_str_;
}

string address::get_path_mode() const
{
    string str;
    
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
    if(const fstream fin(path_); fin.is_open())
        return true;

    cout << "file isn't opened(try_open())!\n";
    return false;
}

address& address::operator=(const address& right)
{
    this->path_ = right.path_;
    return *this;    
}