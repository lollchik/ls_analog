#include <iostream>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

/**
 *  @author Zhurckov G.S.
 *  @brief
 *  Всспомогательные функции используеме для формирования вывода.
 */
// Вывод расширенной информации о файле
void print_directory_large_info(vector<string> *entries, std::string &folder_path, bool is_human_readble = false);

// Вывод размера файла в удобном формате
string human_readable_size(uintmax_t size);

// Получение прав доступа
string get_rights(mode_t mode);

// Получение ссылок
string get_rights(mode_t mode);

// Форматирование времени
string format_time(time_t time);

// сортировки
void alphabetical_order_sort(vector<string> *entries);
void revesrs_alphabetical_order_sort(vector<string> *entries);