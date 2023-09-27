// ReSharper disable CommentTypo
// ReSharper disable CppClangTidyModernizeRawStringLiteral
// ReSharper disable StringLiteralTypo
// ReSharper disable CppClangTidyConcurrencyMtUnsafe
#define VERSION "v1.2.1"
#include <iostream>
#include "io.h"
#include "time.h"  // NOLINT(modernize-deprecated-headers)
#include "sort.h"
#include "struct.h"
using namespace std;

int main(int argc, char* argv[])
{
    const string paths = "C:\\Users\\User\\Documents";
    const string paths_name = "C:\\Users\\User\\Documents\\names.csv";
    const string paths_name_out = "C:\\Users\\User\\Documents\\names_out.csv";
    address names_adr(paths_name, address::absolute, address::custom);
    address names_adr_out(paths_name_out,address::absolute, address::custom);

    constexpr int num = 5000;
    int n = 100;
    
    int a[num]{};
    string a_s[num]{};
    my_struct ms_int{};
    ms_int.Int = a;
    my_struct ms_str{};
    ms_str.str = a_s;
    ms_str.type = _Str;
    
    read(ms_str, names_adr);
    literal_sort(ms_str, num);
    write(ms_str, names_adr_out, num);
    
    address path(paths), path_out(paths, address::write);
    mode mode1 = address::relative;
    string str_m;
    
    while (true)
    {
        system("cls");
        
        int choice = 0;
        
        if(mode1 == static_cast<mode>(0))
            str_m = "relative";
        else if(mode1 == static_cast<mode>(1))
            str_m = "absolute";
        
        cout << "It's a sorting programm " VERSION "\n\n"
                "1.set mode [" << str_m << "]\n"
                "2.set path to in.csv file [" << path.get_address() << "] (in [" << path.get_mode() << "] mode)\n"
                "3.set path to out.csv file [" << path_out.get_address() << "] (in [" << path_out.get_mode() << "] mode)\n"
                "4.set path for both\n"
                "5.number of iterations for testing [" << n << "]\n"
                "6.full test of sorting\n"
                "7.test of sorting [" << n << "] times with [" << num << "] of elements\n"
                "8.exit\n";
        
        cin >> choice;
        
        switch (choice)
        {
        case 1:
            {
                int t = 0;
                system("cls");
                cout << "set mode:\n0.relative\n1.absolute\nmode is:";
                cin >> t;
                if(t == 0)
                    mode1 = static_cast<mode>(t);  // NOLINT(bugprone-branch-clone)
                else if(t == 1)
                    mode1 = static_cast<mode>(t);
                else
                {
                    cout << "wrong number!\n";
                    system("pause");
                }
                
                break;
            }
        case 2:
            {
                system("cls");
                string s_path;
                cout << "enter the " << str_m << " address of indata file(.csv):";
                cin >> s_path;
                path.set_address(s_path, mode1, address::read);
                break;
            }
        case 3:
            {
                system("cls");
                string s_path;
                cout << "enter the " << str_m << " address of outdata file(.csv):";
                cin >> s_path;
                path_out.set_address(s_path, mode1, address::write);
                break;
            }
        case 4:
            {
                system("cls");
                string s_path;
                cout << "enter the address to files:";
                cin >> s_path;
                path.set_address(s_path, mode1, address::read);
                path_out.set_address(s_path, mode1, address::write);
                break;
            }
        case 5:
            {
                system("cls");
                cout << "set number of iterations :";
                cin >> n;
                break;
            }
        case 6:
            {
                system("cls");
                cout << "full test of sorting\n\n";
                full_test(ms_int, num, n, path);
                system("pause");
                break;
            }
        case 7:
            {
                system("cls");
                int choice_2 = 0;
                cout << "1.bubble_sort\n"
                        "2.selection_sort\n"
                        "3.insertion_sort\n"
                        "4.q_sort\n"
                        "5.\n"
                        "6.shell_sort\n"
                        "7.heap_sort\n"
                        "8.literal_sort\n";
                cin >> choice_2;
                switch (choice_2)
                {
                case 1:
                    {
                        system("cls");
                        cout << "bubble_sort:\n" << test(bubble_sort, ms_int, num, n, path) << "\n\n";
                        break;
                    }
                case 2:
                    {
                        system("cls");
                        cout << "selection_sort:\n" << test(selection_sort, ms_int, num, n, path) << "\n\n";
                        break;
                    }
                case 3:
                    {
                        system("cls");
                        cout << "insertion_sort:\n" << test(insertion_sort, ms_int, num, n, path) << "\n\n";
                        break;
                    }
                case 4:
                    {
                        system("cls");
                        cout << "q_sort:\n" << test(q_sort, ms_int, num, n, path) << "\n\n";
                        break;
                    }
                case 5:
                    {
                        system("cls");
                        cout << "it's not work yet\n";
                        cout << "shell_sort:\n" << test(merge_sort, ms_int, num, n, path) << "\n\n";
                        system("pause");
                        break;
                    }
                case 6:
                    {
                        system("cls");
                        // cout << "shell_sort:\n" << test(shell_sort, ms, num, n, path) << "\n\n";
                        break;
                    }
                case 7:
                    {
                        system("cls");
                        cout << "heap_sort:\n" << test(heap_sort, ms_int, num, n, path) << "\n\n";
                        break;
                    }
                case 8:
                    {
                        system("cls");
                        cout << "literal_sort:\n" << test(literal_sort, ms_str, num, n, path) << "\n\n";
                        break;
                    }
                default:
                    {
                        cout << "wrong number!\n";
                        system("pause");
                        break;
                    }
                }
                system("pause");
                break;
            }
        case 8:
            {
                write(ms_int, path_out, num);
                goto end;  // NOLINT(cppcoreguidelines-avoid-goto, hicpp-avoid-goto)
            }
        default:
            {
                cout << "wrong number!\n";
                system("pause");
                break;
            }
        }
    }
    
    end:
    return 0;
}