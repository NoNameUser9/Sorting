// ReSharper disable CommentTypo
// ReSharper disable CppClangTidyModernizeRawStringLiteral
// ReSharper disable StringLiteralTypo
// ReSharper disable CppClangTidyConcurrencyMtUnsafe
#define VERSION "v1.3.0"
#include <iostream>
#include "io.h"
#include "time.h"  // NOLINT(modernize-deprecated-headers)
#include "sort.h"
#include "struct.h"

using namespace std;

int main(int argc, char* argv[])
{
    constexpr int num = 5000;
    int n = 1; //число итераций time()  // NOLINT(clang-diagnostic-invalid-utf8)
    
    int a[num]{};
    string a_s[num]{};
    dualtype ms{};
    ms.Int = a;
    ms.Str = a_s;
    
    address path("C:\\Users\\User\\Documents\\data.csv"),
    path_out("C:\\Users\\User\\Documents\\data_out.csv", address::write);
    path.set_address_str("C:\\Users\\User\\Documents\\names.csv");
    path_out.set_address_str("C:\\Users\\User\\Documents\\names_out.csv");
    
    path_mode mode1 = address::relative;
    string str_m;
    
    while (true)
    {
        system("cls");
        
        int choice = 0;
        
        if(mode1 == static_cast<path_mode>(0))
            str_m = "relative";
        else if(mode1 == static_cast<path_mode>(1))
            str_m = "absolute";
        
        cout << "It's a sorting programm " VERSION "\n\n"
                "1.set mode [" << str_m << "]\n"
                "2.set path to in.csv file [" << path.get_address() << "] (in [" << path.get_path_mode() << "] mode)\n"
                "3.set path to out.csv file [" << path_out.get_address() << "] (in [" << path_out.get_path_mode() << "] mode)\n"
                "4.\n"/*set path for both*/
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
                cout << "set mode:\n"
                        "0.relative\n"
                        "1.absolute\n"
                        "mode is:";
                cin >> t;
                if(t == 0)
                    mode1 = static_cast<path_mode>(t);  // NOLINT(bugprone-branch-clone)
                else if(t == 1)
                    mode1 = static_cast<path_mode>(t);
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
                cout << "don't work now!\n";
                system("pause");
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
                full_test(ms, num, n, path, false);
                ms.is_Str_read = true;
                write(ms, path_out, num);
                write(ms, path_out, num);
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
                        "5.merge_sort\n"
                        "6.shell_sort\n"
                        "7.heap_sort\n"
                        "8.literal_sort\n";
                
                cin >> choice_2;
                switch (choice_2)
                {
                case 1:
                    {
                        system("cls");
                        cout << "bubble_sort:\n" << test(bubble_sort, ms, num, n, path, false) << "\n\n";
                        write(ms, path_out, num);
                        break;
                    }
                case 2:
                    {
                        system("cls");
                        cout << "selection_sort:\n" << test(selection_sort, ms, num, n, path, false) << "\n\n";
                        write(ms, path_out, num);
                        break;
                    }
                case 3:
                    {
                        system("cls");
                        cout << "insertion_sort:\n" << test(insertion_sort, ms, num, n, path, false) << "\n\n";
                        write(ms, path_out, num);
                        break;
                    }
                case 4:
                    {
                        system("cls");
                        cout << "q_sort:\n" << test(q_sort, ms, num, n, path, false) << "\n\n";
                        write(ms, path_out, num);
                        break;
                    }
                case 5:
                    {
                        system("cls");
                        cout << "it's not work yet!\n";
                        cout << "merge_sort:\n" << test(merge_sort, ms, num, n, path, false) << "\n\n";
                        write(ms, path_out, num);
                        break;
                    }
                case 6:
                    {
                        system("cls");
                        cout << "shell_sort:\n" << test(shell_sort, ms, num, n, path, false) << "\n\n";
                        write(ms, path_out, num);
                        break;
                    }
                case 7:
                    {
                        system("cls");
                        cout << "heap_sort:\n" << test(heap_sort, ms, num, n, path, false) << "\n\n";
                        write(ms, path_out, num);
                        break;
                    }
                case 8:
                    {
                        system("cls");
                        ms.is_Str_read = true;
                        cout << "literal_sort:\n" << test(literal_sort, ms, num, n, path, false) << "\n\n";
                        address ps(path_out.get_address_str(), path_out.get_mode());                        
                        write(ms, ps, num);
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