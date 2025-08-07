#include <iostream>
#include <dirent.h>
#include <string>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

/*
 @author Zhurckov G.S.
 @brief
    Виртуальный класс для возможности реализации функционала по другому (переход на новый стандарт, повлекший оптимизации).
*/
class DirectoryUtil{
    public:
        DirectoryUtil(const string& input_folder_path): folder_path(input_folder_path){}
        virtual ~DirectoryUtil()= default;
    protected:
        /*some folder info*/
        std::string folder_path;
        virtual void list_directory_info() const = 0;
        virtual void list_directory_large_info() const = 0;
        virtual void list_directory_large_revers_info()  = 0;
        virtual void list_directory_large_humaniod_info() = 0;
        virtual void list_directory_large_revers_humaniod_info() = 0;
};

/*
 @author Zhurckov G.S.
 @brief
    Класс реализации функционала утилиты лс (реализация на основе уловий поставленной задачи).
*/
class UnixDirectoryUtil : protected DirectoryUtil
{
public:
    UnixDirectoryUtil(const string& path):DirectoryUtil(path){};
    void list_directory_info() const override {
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir(this->folder_path.c_str())) != nullptr) {
            cout << "FOLDER FILL: " << this->folder_path << endl;
            while ((ent = readdir(dir)) != nullptr) {
                cout << ent->d_name << endl;
            }
            closedir(dir);
        } else {
            perror("ERR: cant open folder");
        }
    };
    void list_directory_large_info() const override {};
    void list_directory_large_revers_info() override {};
    void list_directory_large_humaniod_info() override {};
    void list_directory_large_revers_humaniod_info() override {};
};

/*
 @author Zhurckov G.S.
 @brief
    Функция посследовательно перебирает аргументы переданные на вход,
    в зависимости от полученных аргументов запускаются необходимые сценари.
*/
int main(int argc, char *argv[]) {
    
    //	opterr = 0;
    int rez = 0;
    int result_storage = 0;
    int flag = 0;
    bool is_comand_with_flag = false;
	while ( (rez = getopt(argc, argv, "lrhH")) != -1){
        cout<<"RES"<<rez<<endl;
        is_comand_with_flag = true;
        switch (rez) {
            case 'l':   result_storage = rez; printf("<-------Using l key large output---------->\n"); 
                        UnixDirectoryUtil(".").list_directory_large_info();            
                        break;

            case 'r':   printf("<-------Using r key revers output--------->\n");
                        if(!result_storage & !flag)
                            UnixDirectoryUtil(".").list_directory_large_revers_humaniod_info();
                        else if(!result_storage)
                            UnixDirectoryUtil(".").list_directory_large_revers_info();    
                        break;

            case 'h':   printf("<-------Using h key humanoid output)------>\n");
                        if(!result_storage & !flag)
                            UnixDirectoryUtil(".").list_directory_large_revers_humaniod_info();
                        else if(!result_storage)
                            UnixDirectoryUtil(".").list_directory_large_revers_humaniod_info();
                        break;
            
            case 'H':   printf("HI, there is ls alternative usege helper! =)\n  -l : \"some info about l\"\n  -r : \"some info about r\"\n  -h : \"some info about h\"\n  -H : \"some info about H\"\n"); break;
            case '?':   printf("UNKNOWN OPTION USE -H for help printing !\n"); break;
		}
	}
    if(!is_comand_with_flag)
        UnixDirectoryUtil(".").list_directory_info();
    return 0;
}
