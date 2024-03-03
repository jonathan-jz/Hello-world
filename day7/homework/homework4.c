#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

void copy_file(const char *src_path, const char *dst_path) {
    int src_fd = open(src_path, O_RDONLY);
    if (src_fd == -1) {
        perror("open");
        return;
    }

    int dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (dst_fd == -1) {
        perror("open");
        close(src_fd);
        return;
    }

    char buf[BUF_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(src_fd, buf, BUF_SIZE)) > 0) {
        bytes_written = write(dst_fd, buf, bytes_read);
        if (bytes_written != bytes_read) {
            perror("write");
            close(src_fd);
            close(dst_fd);
            return;
        }
    }

    if (bytes_read == -1) {
        perror("read");
    }

    close(src_fd);
    close(dst_fd);
}

void copy_dir(const char *src_path, const char *dst_path) {
    DIR *dir = opendir(src_path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    if (mkdir(dst_path, 0777) == -1) {
        perror("mkdir");
        return;
    }

    struct dirent *entry;
    struct stat statbuf;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_child_path[PATH_MAX];
        char dst_child_path[PATH_MAX];
        snprintf(src_child_path, PATH_MAX, "%s/%s", src_path, entry->d_name);
        snprintf(dst_child_path, PATH_MAX, "%s/%s", dst_path, entry->d_name);

        if (stat(src_child_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            copy_dir(src_child_path, dst_child_path);
        } else {
            copy_file(src_child_path, dst_child_path);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    copy_dir(argv[1], argv[2]);

    return 0;
}
