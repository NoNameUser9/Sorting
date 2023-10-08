// ReSharper disable CommentTypo
// ReSharper disable CppClangTidyModernizeRawStringLiteral
// ReSharper disable StringLiteralTypo
// ReSharper disable CppClangTidyConcurrencyMtUnsafe
#define VERSION "v1.5.0"
#include <iostream>
#include "io.h"
#include "time.h"  // NOLINT(modernize-deprecated-headers)
#include "sort.h"
#include "struct.h"

using namespace std;

int main(int argc, char* argv[])
{
    address pa("C:\\Users\\User\\Documents\\Sort.csv"),
    pa_out("C:\\Users\\User\\Documents\\Sort_out.csv", address::write),
    path("C:\\Users\\User\\Documents\\Moscow.csv"),
    path_out("C:\\Users\\User\\Documents\\Moscow_out.csv", address::write);
    
    uint16_t n = 1; //число итераций time()  // NOLINT(clang-diagnostic-invalid-utf8)
    dualtype dt{};
    dualtype dt_t{};
    read_vec(dt_t, pa);
    bool tl = true;
    
    path_mode mode1 = address::relative;
    string str_m;
    dt.str_or_int = false;

    
    uint16_t col = 1;
    while (true)
    {
        system("cls");
        
        if(mode1 == static_cast<path_mode>(0))
            str_m = "relative";
        else if(mode1 == static_cast<path_mode>(1))
            str_m = "absolute";
        
        cout << "It's a sorting programm " VERSION "\n\n"
                "1.set mode [" << str_m << "]\n"
                "2.set path to in.csv file [" << path.get_address() << "] (in [" << path.get_path_mode() << "] mode)\n"
                "3.set path to out.csv file [" << path_out.get_address() << "] (in [" << path_out.get_path_mode() << "] mode)\n"
                "4.set to_low state\n"/*set path for both*/
                "5.number of iterations for testing [" << dt_t.Table.size()-1 << "]\n"
                "6.full test of sorting\n"
                "7.test of sorting [" << n << "] times with [" << dt_t.Table.size()-1 << "] of elements\n"
                "8.set col[" << col << "]\n"
                "9.exit\n";
        
        uint16_t choice = 0;
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
                cout << "set tl state\n0.false\n1.true\n";
                cin >> tl;
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
                full_test(dt, n, path, col, false);
                dt.is_Str_read = true;
                write_vec(dt, path_out);
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
                        chrono::duration<double, ratio<1, 1>> time{};
                        time = test(bubble_sort, dt, n, path, col, tl);
                        cout << "bubble_sort:\n" << time << "\n\n";
                        write_vec(dt, path_out);
                        sort_type st;
                        st.set_name(sort_type::bubble);
                        write_vec_sort_time(dt_t, 1, st, time);
                        address pt(pa.get_address(), address::write);
                        write_vec(dt_t, pt);
                        break;
                    }
                case 2:
                    {
                        system("cls");
                        chrono::duration<double, ratio<1, 1>> time{};
                        time = test(selection_sort, dt, n, path, col, tl);
                        cout << "selection_sort:\n" << time << "\n\n";
                        write_vec(dt, path_out);
                        sort_type st;
                        st.set_name(sort_type::selection);
                        write_vec_sort_time(dt_t, 1, st, time);
                        address pt(pa.get_address(), address::write);
                        write_vec(dt_t, pt);
                        break;
                    }
                case 3:
                    {
                        system("cls");
                        chrono::duration<double, ratio<1, 1>> time{};
                        time = test(insertion_sort, dt, n, path, col, tl);
                        cout << "insertion_sort:\n" << time << "\n\n";
                        write_vec(dt, path_out);
                        sort_type st;
                        st.set_name(sort_type::insertion);
                        write_vec_sort_time(dt_t, 1, st, time);
                        address pt(pa.get_address(), address::write);
                        write_vec(dt_t, pt);
                        break;
                    }
                case 4:
                    {
                        system("cls");
                        chrono::duration<double, ratio<1, 1>> time{};
                        time = test(q_sort, dt, n, path, col, tl);
                        cout << "q_sort:\n" << time << "\n\n";
                        write_vec(dt, path_out);
                        sort_type st;
                        st.set_name(sort_type::q_sort);
                        write_vec_sort_time(dt_t, 1, st, time);
                        address pt(pa.get_address(), address::write);
                        write_vec(dt_t, pt);
                        break;
                    }
                case 5:
                    {
                        system("cls");
                        // cout << "it's not work yet!\n";
                        chrono::duration<double, ratio<1, 1>> time{};
                        time = test(merge_sort, dt, n, path, col, tl);
                        cout << "merge_sort:\n" << time << "\n\n";
                        write_vec(dt, path_out);
                        sort_type st;
                        st.set_name(sort_type::merge);
                        write_vec_sort_time(dt_t, 1, st, time);
                        address pt(pa.get_address(), address::write);
                        write_vec(dt_t, pt);
                        break;
                    }
                case 6:
                    {
                        system("cls");
                        chrono::duration<double, ratio<1, 1>> time{};
                        time = test(shell_sort, dt, n, path, col, tl);
                        cout << "shell_sort:\n" << time << "\n\n";
                        write_vec(dt, path_out);
                        sort_type st;
                        st.set_name(sort_type::shell);
                        write_vec_sort_time(dt_t, 1, st, time);
                        address pt(pa.get_address(), address::write);
                        write_vec(dt_t, pt);
                        break;
                    }
                case 7:
                    {
                        system("cls");
                        chrono::duration<double, ratio<1, 1>> time{};
                        time = test(heap_sort, dt, n, path, col, tl);
                        cout << "heap_sort:\n" << time << "\n\n";
                        write_vec(dt, path_out);
                        sort_type st;
                        st.set_name(sort_type::heap);
                        write_vec_sort_time(dt_t, 1, st, time);
                        address pt(pa.get_address(), address::write);
                        write_vec(dt_t, pt);
                        break;
                    }
                case 8:
                    {
                        system("cls");
                        // dt.is_Str_read = true;
                        chrono::duration<double, ratio<1, 1>> time{};
                        time = test(literal_sort, dt, n, path, col, tl);
                        cout << "literal_sort:\n" << time << "\n\n";
                        write_vec(dt, path_out);
                        sort_type st;
                        st.set_name(sort_type::literal);
                        write_vec_sort_time(dt_t, 1, st, time);
                        address pt(pa.get_address(), address::write);
                        write_vec(dt_t, pt);
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
                system("cls");
                cout << "set col num\n";
                cin >> col;
                break;
            }
        case 9:
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