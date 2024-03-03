#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

// 显示目录的 ls -l 效果
void display_ls_l(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    struct stat statbuf;
    while ((entry = readdir(dir)) != NULL) {
        char full_path[PATH_MAX];
        snprintf(full_path, PATH_MAX, "%s/%s", dir_path, entry->d_name);

        if (stat(full_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        // 打印文件类型和权限
        printf((S_ISDIR(statbuf.st_mode)) ? "d" : "-");
        printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
        printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
        printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
        printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
        printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
        printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
        printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
        printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
        printf((statbuf.st_mode & S_IXOTH) ? "x" : "-");

        // 打印硬链接数、所有者、所属组、文件大小、最后修改时间和文件名
        struct passwd *pw = getpwuid(statbuf.st_uid);
        struct group *gr = getgrgid(statbuf.st_gid);
        printf(" %2ld %s %s %8ld %s %s\n",
               (long)statbuf.st_nlink, pw->pw_name, gr->gr_name,
               (long)statbuf.st_size, ctime(&statbuf.st_mtime), entry->d_name);
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    display_ls_l(argv[1]);

    return 0;
}
