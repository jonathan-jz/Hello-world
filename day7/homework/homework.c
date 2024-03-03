#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <dirent.h>

// 搜索指定路径下是否存在指定文件，并打印该文件的绝对路径
void search_file(const char *dir_path, const char *file_name) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    struct stat statbuf;
    char full_path[PATH_MAX];

    while ((entry = readdir(dir)) != NULL) {
        snprintf(full_path, PATH_MAX, "%s/%s", dir_path, entry->d_name);

        if (stat(full_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISREG(statbuf.st_mode) && strcmp(entry->d_name, file_name) == 0) {
            char real_path[PATH_MAX];
            if (realpath(full_path, real_path) == NULL) {
                perror("realpath");
                closedir(dir);
                return;
            }

            printf("Found file %s at path: %s\n", file_name, real_path);
            closedir(dir);
            return;
        }
    }

    printf("File %s not found in directory %s\n", file_name, dir_path);
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory> <file_name>\n", argv[0]);
        return 1;
    }

    search_file(argv[1], argv[2]);

    return 0;
}
