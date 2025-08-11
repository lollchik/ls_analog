#include <iostream>
#include <dirent.h>
#include <string>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream> 

using namespace std;

string human_readable_size(uintmax_t size);

// Функция для получения строки прав доступа
string get_permissions(mode_t mode);

// Функция для форматирования времени
string format_time(time_t time);
