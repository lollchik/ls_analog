#include "directory_util.h"

using namespace std;

/*
 @author Zhurckov G.S.
 @brief
    Функция посследовательно перебирает аргументы переданные на вход,
    в зависимости от полученных аргументов запускаются необходимые сценари.
*/
int main(int argc, char *argv[])
{
    char *path;
    int rez = 0;
    bool is_l = false, is_r = false, is_h = false;
    while ((rez = getopt(argc, argv, "lrhH")))
    {
        if (rez == -1)
        {
            if (argv[optind] == NULL)
                path = (char *)".";
            else
                path = argv[optind];
            if (is_l & (!is_r & !is_h))
                UnixDirectoryUtil(path).list_directory_large_info();
            else if (is_l & is_r & !is_h)
                UnixDirectoryUtil(path).list_directory_large_revers_info();
            else if (is_l & is_h & !is_r)
                UnixDirectoryUtil(path).list_directory_large_humaniod_info();
            else if (is_l & is_r & is_h)
                UnixDirectoryUtil(path).list_directory_large_revers_humaniod_info();
            else
                UnixDirectoryUtil(path).list_directory_info();
            break;
        }
        switch (rez)
        {
        case 'l':
            is_l = true;
            break;
        case 'r':
            is_r = true;
            break;
        case 'h':
            is_h = true;
            break;
        case 'H':
            printf("HI, there is ls alternative usege helper! =)\n  -l : \"some info about l\"\n  -r : \"some info about r\"\n  -h : \"some info about h\"\n  -H : \"some info about H\"\n");
            break;
        case '?':
            printf("UNKNOWN OPTION USE -H for help printing !\n");
            break;
        }
    }
    return 0;
}
