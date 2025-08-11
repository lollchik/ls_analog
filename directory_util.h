#include "helpers_func.h"

using namespace std;

/*
 @author Zhurckov G.S.
 @brief
    Класс реализации функционала утилиты лс (реализация на основе уловий поставленной задачи).
*/
class UnixDirectoryUtil
{
    string folder_path;

public:
    UnixDirectoryUtil(const string &path) : folder_path(path) {};
    void list_directory_info() const;
    void list_directory_large_info() const;
    void list_directory_large_revers_info();
    void list_directory_large_humaniod_info();
    void list_directory_large_revers_humaniod_info();
};