#include "io.h"
#include <fstream>
#include <iostream>
#include <sstream>

void read(int* a, const string& path)
{
    string line;
    fstream fin(path);
    stringstream ss;
    
    for(int i = 0; getline(fin, line); ++i)
    {
        ss.clear();
        ss << line;
        ss >> a[i];
    }
    
    fin.close();
}

void write(const int* a, const string& path, const int num)
{
    // ReSharper disable once IdentifierTypo
    fstream fout;
    stringstream ss;
    
    fout.open(path, fstream::trunc|fstream::out);
    
    if(!fout.is_open())
        cout << "file not opened";
    
    for(int i = 0; i < num; ++i)
    {
        ss.clear();
        string str = to_string(a[i])+'\n';
        fout.write(str.c_str(), static_cast<streamsize>(str.size()));
    }

    fout.close();
}

void print(auto* arr, const int num)
{
    for(int i = 0; i < num; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}