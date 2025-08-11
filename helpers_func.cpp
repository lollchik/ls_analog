#include "helpers_func.h"

string human_readable_size(uintmax_t size) {
    const vector<string> units = {"KB", "MB", "GB", "TB"};
    size_t unit_index = 0;
    double human_size = size;
    bool is_human_size = true;

    while (human_size >= 1024 && unit_index < units.size() - 1) {
        is_human_size = false;
        human_size /= 1024;
        unit_index++;
    }

    ostringstream oss;
    if(!is_human_size)
    oss << fixed << setprecision(1) << human_size << units[unit_index];
    else
    oss << fixed << setprecision(1) << human_size;
    string result = oss.str();
    
    // Удаляем .0 для целых чисел
    size_t dot_pos = result.find(".0");
    if (dot_pos != string::npos && dot_pos + 2 == result.size() - units[unit_index].size()) {
        result.erase(dot_pos, 2);
    }

    return result;
}

// Функция для получения строки прав доступа
string get_permissions(mode_t mode)
{
    string permissions;

    // Тип файла
    permissions += (S_ISDIR(mode)) ? 'd' : 
                   (S_ISLNK(mode)) ? 'l' : 
                   (S_ISCHR(mode)) ? 'c' : 
                   (S_ISBLK(mode)) ? 'b' : 
                   (S_ISFIFO(mode))? 'p' : 
                   (S_ISSOCK(mode))? 's' : 
                   '-';
    // Права владельца
    permissions += (mode & S_IRUSR) ? 'r' : '-';
    permissions += (mode & S_IWUSR) ? 'w' : '-';
    permissions += (mode & S_IXUSR) ? 'x' : '-';
    // Права группы
    permissions += (mode & S_IRGRP) ? 'r' : '-';
    permissions += (mode & S_IWGRP) ? 'w' : '-';
    permissions += (mode & S_IXGRP) ? 'x' : '-';
    // Права остальных
    permissions += (mode & S_IROTH) ? 'r' : '-';
    permissions += (mode & S_IWOTH) ? 'w' : '-';
    permissions += (mode & S_IXOTH) ? 'x' : '-';

    return permissions;
}

// Функция для форматирования времени
string format_time(time_t time)
{
    char buffer[32];
    struct tm *tm_info = localtime(&time);
    strftime(buffer, sizeof(buffer), "%b %d %H:%M", tm_info);
    return buffer;
}
