#include "helpers_func.h"

string human_readable_size(uintmax_t size)
{
    const vector<string> units = {"B", "KB", "MB", "GB", "TB"};
    size_t unit_index = 0;
    double human_size = size;
    bool is_human_size = true;

    while (human_size >= 1024 && unit_index < units.size() - 1)
    {
        is_human_size = false;
        human_size /= 1024;
        unit_index++;
    }

    ostringstream oss;
    if (!is_human_size)
        oss << fixed << setprecision(1) << human_size << units[unit_index];
    else
        oss << fixed << setprecision(1) << human_size;
    string result = oss.str();

    size_t dot_pos = result.find(".0");
    if (dot_pos != string::npos)
    {
        result.erase(dot_pos, 2);
    }

    return result;
}

string get_rights(mode_t mode)
{
    string rights;

    rights += (S_ISDIR(mode)) ? 'd' : (S_ISLNK(mode)) ? 'l'
                                  : (S_ISCHR(mode))   ? 'c'
                                  : (S_ISBLK(mode))   ? 'b'
                                  : (S_ISFIFO(mode))  ? 'p'
                                  : (S_ISSOCK(mode))  ? 's'
                                                      : '-';
    rights += (mode & S_IRUSR) ? 'r' : '-';
    rights += (mode & S_IWUSR) ? 'w' : '-';
    rights += (mode & S_IXUSR) ? 'x' : '-';
    rights += (mode & S_IRGRP) ? 'r' : '-';
    rights += (mode & S_IWGRP) ? 'w' : '-';
    rights += (mode & S_IXGRP) ? 'x' : '-';
    rights += (mode & S_IROTH) ? 'r' : '-';
    rights += (mode & S_IWOTH) ? 'w' : '-';
    rights += (mode & S_IXOTH) ? 'x' : '-';

    return rights;
}

string format_time(time_t time)
{
    char buffer[32];
    struct tm *tm_info = localtime(&time);
    strftime(buffer, sizeof(buffer), "%b %d %H:%M", tm_info);
    return buffer;
}

void alphabetical_order_sort(vector<string> *entries)
{
    sort(entries->begin(), entries->end(), [](const string &a, const string &b)
         { return strcasecmp(a.c_str(), b.c_str()) < 0; });
}

void revesrs_alphabetical_order_sort(vector<string> *entries)
{
    sort(entries->begin(), entries->end(), [](const string &a, const string &b)
         { return strcasecmp(a.c_str(), b.c_str()) > 0; });
}

void print_directory_large_info(vector<string> *entries, std::string &folder_path, bool is_human_readble)
{
    double total = 0;
    for (const auto &name : *entries)
    {
        string full_path = string(folder_path) + "/" + name;
        struct stat file_stat;

        if (lstat(full_path.c_str(), &file_stat))
        {
            cerr << "ERR: read file_stat error f :" << name << "\n";
            continue;
        }
        total += file_stat.st_size;
    }

    if (is_human_readble)
        cout << "total " << human_readable_size(total) << endl;
    else
        cout << "total " << total << endl;

    for (const auto &name : *entries)
    {
        if (name[0] != 46 && name[0] != 11822)
        {
            string full_path = string(folder_path) + "/" + name;
            struct stat file_stat;

            if (lstat(full_path.c_str(), &file_stat))
            {
                cerr << "ERR: read file_stat error f :" << name << "\n";
                continue;
            }

            cout << get_rights(file_stat.st_mode) << " ";
            cout << setw(3) << file_stat.st_nlink << " ";
            cout << getpwuid(file_stat.st_uid)->pw_name << " ";
            cout << getgrgid(file_stat.st_gid)->gr_name << " ";
            if (is_human_readble)
                cout << setw(8) << human_readable_size(file_stat.st_size) << " ";
            else
                cout << setw(8) << file_stat.st_size << " ";
            cout << format_time(file_stat.st_mtime) << " ";
            if (S_ISLNK(file_stat.st_mode))
            {
                char link_target[1024];
                ssize_t len = readlink(full_path.c_str(), link_target, sizeof(link_target) - 1);
                link_target[len] = '\0';
                cout << name << " -> " << link_target << endl;
            }
            else
                cout << name << endl;
        }
    }
}
