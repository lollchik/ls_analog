#include "directory_util.h"

void UnixDirectoryUtil::list_directory_info() const
{
    DIR *dir;
    struct dirent *ent;
    vector<string> entries;
    if ((dir = opendir(this->folder_path.c_str())) != nullptr)
    {
        cout << "FOLDER FILL: " << this->folder_path << endl;
        while ((ent = readdir(dir)) != nullptr)
        {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
                entries.push_back(ent->d_name);
        }
        sort(entries.begin(), entries.end(), [](const string &a, const string &b)
             { return strcasecmp(a.c_str(), b.c_str()) < 0; });
        for (const auto &name : entries)
            cout << name << " ";
        cout << endl;
        closedir(dir);
    }
    else
    {
        perror("ERR: cant open folder");
    }
};

void UnixDirectoryUtil::list_directory_large_info() const
{
    cout << "list_directory_large_info" << endl;
    DIR *dir;
    struct dirent *ent;
    vector<string> entries;
    cout << this->folder_path << endl;

    if ((dir = opendir(this->folder_path.c_str())) != nullptr)
    {
        while ((ent = readdir(dir)) != nullptr)
        {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
                entries.push_back(ent->d_name);
        }
        closedir(dir);
    }
    else
    {
        perror("ERR: cant open folder");
    }

    struct dirent *entry;

    // Сортируем по алфавиту (как в ls)
    sort(entries.begin(), entries.end(), [](const string &a, const string &b)
         { return strcasecmp(a.c_str(), b.c_str()) < 0; });

    // Выводим информацию для каждого файла
    for (const auto &name : entries)
    {
        string full_path = string(this->folder_path) + "/" + name;

        struct stat file_stat;
        if (lstat(full_path.c_str(), &file_stat))
        {
            cerr << "Ошибка при получении информации о файле: " << name << "\n";
            continue;
        }

        // Права доступа
        cout << get_permissions(file_stat.st_mode) << " ";
        // Количество ссылок
        cout << setw(3) << file_stat.st_nlink << " ";
        // Владелец
        struct passwd *pwd = getpwuid(file_stat.st_uid);
        cout << (pwd ? pwd->pw_name : "unknown") << " ";
        // Группа
        struct group *grp = getgrgid(file_stat.st_gid);
        cout << (grp ? grp->gr_name : "unknown") << " ";
        // Размер файла
        cout << setw(8) << file_stat.st_size << " ";
        // Время модификации
        cout << format_time(file_stat.st_mtime) << " ";
        // Имя файла
        if (S_ISLNK(file_stat.st_mode))
        {
            // Для симлинков показываем цель
            char link_target[1024];
            ssize_t len = readlink(full_path.c_str(), link_target, sizeof(link_target) - 1);
            if (len != -1)
            {
                link_target[len] = '\0';
                cout << name << " -> " << link_target;
            }
            else
            {
                cout << name << " -> [некорректная ссылка]";
            }
        }
        else
        {
            cout << name;
        }
        cout << "\n";
    }
};
void UnixDirectoryUtil::list_directory_large_revers_info()
{
    cout << "list_directory_large_revers_info" << endl;
    DIR *dir;
    struct dirent *ent;
    vector<string> entries;
    cout << this->folder_path << endl;

    if ((dir = opendir(this->folder_path.c_str())) != nullptr)
    {
        while ((ent = readdir(dir)) != nullptr)
        {
            entries.push_back(ent->d_name);
        }
        closedir(dir);
    }
    else
    {
        perror("ERR: cant open folder");
    }

    struct dirent *entry;

    // Сортируем по алфавиту (как в ls)
    sort(entries.begin(), entries.end(), [](const string &a, const string &b)
         { return strcasecmp(a.c_str(), b.c_str()) > 0; });

    // Выводим информацию для каждого файла
    for (const auto &name : entries)
    {
        string full_path = string(this->folder_path) + "/" + name;

        struct stat file_stat;
        if (lstat(full_path.c_str(), &file_stat))
        {
            cerr << "Ошибка при получении информации о файле: " << name << "\n";
            continue;
        }
        // Права доступа
        cout << get_permissions(file_stat.st_mode) << " ";
        // Количество ссылок
        cout << setw(3) << file_stat.st_nlink << " ";
        // Владелец
        struct passwd *pwd = getpwuid(file_stat.st_uid);
        cout << (pwd ? pwd->pw_name : "unknown") << " ";
        // Группа
        struct group *grp = getgrgid(file_stat.st_gid);
        cout << (grp ? grp->gr_name : "unknown") << " ";
        // Размер файла
        cout << setw(8) << file_stat.st_size << " ";
        // Время модификации
        cout << format_time(file_stat.st_mtime) << " ";
        // Имя файла
        if (S_ISLNK(file_stat.st_mode))
        {
            // Для симлинков показываем цель
            char link_target[1024];
            ssize_t len = readlink(full_path.c_str(), link_target, sizeof(link_target) - 1);
            if (len != -1)
            {
                link_target[len] = '\0';
                cout << name << " -> " << link_target;
            }
            else
            {
                cout << name << " -> [некорректная ссылка]";
            }
        }
        else
        {
            cout << name;
        }

        cout << "\n";
    }
};
void UnixDirectoryUtil::list_directory_large_humaniod_info()
{
    cout << "list_directory_large_humaniod_info" << endl;
    DIR *dir;
    struct dirent *ent;
    vector<string> entries;
    cout << this->folder_path << endl;

    if ((dir = opendir(this->folder_path.c_str())) != nullptr)
    {
        while ((ent = readdir(dir)) != nullptr)
        {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0)
                entries.push_back(ent->d_name);
        }
        closedir(dir);
    }
    else
    {
        perror("ERR: cant open folder");
    }

    struct dirent *entry;

    // Сортируем по алфавиту (как в ls)
    sort(entries.begin(), entries.end(), [](const string &a, const string &b)
         { return strcasecmp(a.c_str(), b.c_str()) < 0; });

    // Выводим информацию для каждого файла
    for (const auto &name : entries)
    {
        string full_path = string(this->folder_path) + "/" + name;

        struct stat file_stat;
        if (lstat(full_path.c_str(), &file_stat))
        {
            cerr << "Ошибка при получении информации о файле: " << name << "\n";
            continue;
        }

        // Права доступа
        cout << get_permissions(file_stat.st_mode) << " ";
        // Количество ссылок
        cout << setw(3) << file_stat.st_nlink << " ";
        // Владелец
        struct passwd *pwd = getpwuid(file_stat.st_uid);
        cout << (pwd ? pwd->pw_name : "unknown") << " ";
        // Группа
        struct group *grp = getgrgid(file_stat.st_gid);
        cout << (grp ? grp->gr_name : "unknown") << " ";
        // Размер файла
        cout << setw(8) << human_readable_size(file_stat.st_size) << " ";
        // Время модификации
        cout << format_time(file_stat.st_mtime) << " ";
        // Имя файла
        if (S_ISLNK(file_stat.st_mode))
        {
            // Для симлинков показываем цель
            char link_target[1024];
            ssize_t len = readlink(full_path.c_str(), link_target, sizeof(link_target) - 1);
            if (len != -1)
            {
                link_target[len] = '\0';
                cout << name << " -> " << link_target;
            }
            else
            {
                cout << name << " -> [некорректная ссылка]";
            }
        }
        else
        {
            cout << name;
        }
        cout << "\n";
    }
};
void UnixDirectoryUtil::list_directory_large_revers_humaniod_info()
{
    cout << "list_directory_large_revers_humaniod_info" << endl;
    cout << "list_directory_large_revers_humaniod_info" << endl;
    DIR *dir;
    struct dirent *ent;
    vector<string> entries;
    cout << this->folder_path << endl;

    if ((dir = opendir(this->folder_path.c_str())) != nullptr)
    {
        while ((ent = readdir(dir)) != nullptr)
        {
            entries.push_back(ent->d_name);
        }
        closedir(dir);
    }
    else
    {
        perror("ERR: cant open folder");
    }

    struct dirent *entry;

    // Сортируем по алфавиту (как в ls)
    sort(entries.begin(), entries.end(), [](const string &a, const string &b)
         { return strcasecmp(a.c_str(), b.c_str()) > 0; });

    // Выводим информацию для каждого файла
    for (const auto &name : entries)
    {
        string full_path = string(this->folder_path) + "/" + name;

        struct stat file_stat;
        if (lstat(full_path.c_str(), &file_stat))
        {
            cerr << "Ошибка при получении информации о файле: " << name << "\n";
            continue;
        }
        // Права доступа
        cout << get_permissions(file_stat.st_mode) << " ";
        // Количество ссылок
        cout << setw(3) << file_stat.st_nlink << " ";
        // Владелец
        struct passwd *pwd = getpwuid(file_stat.st_uid);
        cout << (pwd ? pwd->pw_name : "unknown") << " ";
        // Группа
        struct group *grp = getgrgid(file_stat.st_gid);
        cout << (grp ? grp->gr_name : "unknown") << " ";
        // Размер файла
        cout << setw(8) << human_readable_size(file_stat.st_size) << " ";
        // Время модификации
        cout << format_time(file_stat.st_mtime) << " ";
        // Имя файла
        if (S_ISLNK(file_stat.st_mode))
        {
            // Для симлинков показываем цель
            char link_target[1024];
            ssize_t len = readlink(full_path.c_str(), link_target, sizeof(link_target) - 1);
            if (len != -1)
            {
                link_target[len] = '\0';
                cout << name << " -> " << link_target;
            }
            else
            {
                cout << name << " -> [некорректная ссылка]";
            }
        }
        else
        {
            cout << name;
        }

        cout << "\n";
    }
};