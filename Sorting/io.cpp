#include "io.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "struct.h"

// ReSharper disable once CppCompileTimeConstantCanBeReplacedWithBooleanConstant
void read(const my_struct& a, const address& path, const std::underlying_type_t<std::byte> type = _Str|_Int)
{
    fstream fin;
    stringstream ss;
    string line;

    fin.open(path.get_address(), fstream::in);

    if(!fin.is_open())
    {
        cout << "\nthe file isn't opened!\n";
        return;
    }

    if(type == _Int)
    {
        for(int i = 0; getline(fin, line); ++i)
        {
            ss.clear();
            ss << line;
            ss >> a.Int[i];
        }
    }
    else if(type == _Str)
    {
        for(int i = 0; getline(fin, line); ++i)
        {
            ss.clear();
            ss << line;
            ss >> a.str[i];
        }
    }
    
    fin.close();
}

void write(const my_struct& a, const address& path, const int num, const std::underlying_type_t<std::byte> type = _Str|_Int)
{
    // ReSharper disable once IdentifierTypo
    fstream fout;
    
    fout.open(path.get_address(), fstream::trunc|fstream::out);
    
    if(!fout.is_open())
    {
        cout << "the file isn't opened!\n";
        return;
    }
    
    if(type == _Int)
    {
        for(int i = 0; i < num; ++i)
        {
            string str = to_string(a.Int[i]) + '\n';
            fout.write(str.c_str(), static_cast<streamsize>(str.size()));
        }
    }
    else if(type == _Str)
    {
        for(int i = 0; i < num; ++i)
        {
            string str = a.str[i] + '\n';
            fout.write(str.c_str(), static_cast<streamsize>(str.size()));
        }
    }

    fout.close();
}

void print(const int* a, const int num)
{
    for(int i = 0; i < num; i++)
        cout << a[i] << " ";
    
    cout << endl;
}

// ReSharper disable once CppPossiblyUninitializedMember
address::address()  // NOLINT(cppcoreguidelines-pro-type-member-init, modernize-use-equals-default)
{
    mode_ = relative;
    wr_mode_ = read;
    wr_ = read_;
    path_ = "~\\" + wr_;
}

// ReSharper disable once CppInconsistentNaming
address::address(const wr_mode WR_mode = write|read)
{
    mode_ = relative;
    
    if(WR_mode == write)
    {
        wr_mode_ = write;
        wr_ = write_;
        path_ = "~\\" + wr_;
    }
    else if(WR_mode == read)
    {
        wr_mode_ = read;
        wr_ = read_;
        path_ = "~\\" + wr_;
    }
}

// ReSharper disable once CppPossiblyUninitializedMember
// ReSharper disable once CppInconsistentNaming
address::address(const string& path, const wr_mode WR_mode = write|read)  // NOLINT(cppcoreguidelines-pro-type-member-init)
{
    if(WR_mode == write)
    {
        wr_mode_ = write;
        wr_ = write_;
        path_ = path + "\\" + wr_;
    }
    else if(WR_mode == read)
    {
        wr_mode_ = read;
        wr_ = read_;
        path_ = path + "\\" + wr_;
    }
    mode_ = absolute;
}

// ReSharper disable once CppPossiblyUninitializedMember
address::address(const string& path)  // NOLINT(cppcoreguidelines-pro-type-member-init)
{
    wr_mode_ = read;
    wr_ = read_;
    path_ = path + "\\" + wr_;
    mode_ = absolute;
}

// ReSharper disable CppInconsistentNaming
// ReSharper disable once CppCompileTimeConstantCanBeReplacedWithBooleanConstant
void address::set_address(const string& path,const mode _Mode = relative|absolute, const wr_mode WR_mode = write|read|custom)  // NOLINT(clang-diagnostic-reserved-identifier, bugprone-reserved-identifier)
// ReSharper restore CppInconsistentNaming
{
    if(WR_mode == write)
    {
        wr_mode_ = write;
        wr_ = write_;
    }
    else if(WR_mode == read)
    {
        wr_mode_ = read;
        wr_ = read_;
    }
    else if(WR_mode == custom)
    {
        wr_mode_ = custom;
        wr_ = custom_;
    }
    
    if(_Mode == relative)
    {
        path_ = "~\\" + path + "\\" + wr_;
        mode_ = relative;
    }
    else if (_Mode == absolute)
    {
        path_ = path + "\\" + wr_;  // NOLINT(bugprone-branch-clone)
        mode_ = absolute;
    }
    else
        cout << "wrong address::get_address _Mode";
}

string address::get_address() const
{
    return path_;
}

string address::get_mode() const
{
    string str;
    
    if(mode_ == relative)
        str = "relative";
    if(mode_ == absolute)
        str = "absolute";
    
    return str;
}

bool address::try_open() const
{
    if(const fstream fin(path_); fin.is_open())
        return true;

    cout << "file isn't opened!\n";
    return false;
}

address& address::operator=(const address& right)
{
    this->path_ = right.path_;
    return *this;    
}