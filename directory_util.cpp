#include "directory_util.h"

void UnixDirectoryUtil::list_directory_info()
{
    if ((this->dir = opendir(this->folder_path.c_str())) != nullptr)
    {
        while ((this->ent = readdir(this->dir)) != nullptr)
        {
            if (this->ent->d_name[0] != 46 && this->ent->d_name[0] != 11822)
                this->entries.push_back(this->ent->d_name);
        }
        sort(this->entries.begin(), this->entries.end(), [](const string &a, const string &b)
             { return strcasecmp(a.c_str(), b.c_str()) < 0; });
        for (const auto &name : this->entries)
            cout << name << " ";
        cout << endl;
        closedir(this->dir);
    }
    else
        perror("ERR: cant open folder");
};

void UnixDirectoryUtil::list_directory_large_info()
{
    cout << "list_directory_large_info" << endl;

    if ((this->dir = opendir(this->folder_path.c_str())) != nullptr)
    {
        while ((this->ent = readdir(this->dir)) != nullptr)
            this->entries.push_back(this->ent->d_name);

        closedir(this->dir);
    }
    else
        perror("ERR: cant open folder");

    alphabetical_order_sort(&this->entries);
    print_directory_large_info(&entries, folder_path);
};
void UnixDirectoryUtil::list_directory_large_revers_info()
{
    cout << "list_directory_large_revers_info" << endl;

    if ((this->dir = opendir(this->folder_path.c_str())) != nullptr)
    {
        while ((this->ent = readdir(this->dir)) != nullptr)
            this->entries.push_back(this->ent->d_name);

        closedir(this->dir);
    }
    else
        perror("ERR: cant open folder");

    revesrs_alphabetical_order_sort(&this->entries);
    print_directory_large_info(&entries, folder_path);
};
void UnixDirectoryUtil::list_directory_large_humaniod_info()
{
    cout << "list_directory_large_humaniod_info" << endl;

    if ((this->dir = opendir(this->folder_path.c_str())) != nullptr)
    {
        while ((this->ent = readdir(this->dir)) != nullptr)
            this->entries.push_back(this->ent->d_name);

        closedir(this->dir);
    }
    else
        perror("ERR: cant open folder");

    alphabetical_order_sort(&entries);
    print_directory_large_info(&entries, folder_path, true);
};
void UnixDirectoryUtil::list_directory_large_revers_humaniod_info()
{
    cout << "list_directory_large_revers_humaniod_info" << endl;

    if ((this->dir = opendir(this->folder_path.c_str())) != nullptr)
    {
        while ((this->ent = readdir(this->dir)) != nullptr)
            this->entries.push_back(this->ent->d_name);

        closedir(this->dir);
    }
    else
        perror("ERR: cant open folder");

    revesrs_alphabetical_order_sort(&entries);
    print_directory_large_info(&entries, folder_path, true);
};