#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *file_path = "test.txt";
    const char *data = "hello";
    const char *new_data = "world";

    // 创建并写入文件
    int fd = open(file_path, O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    write(fd, data, strlen(data));
    close(fd);

    // 映射文件到内存
    fd = open(file_path, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        close(fd);
        return 1;
    }
    char *addr = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    // 修改内存中的内容为 "world"
    memcpy(addr, new_data, strlen(new_data));

    // 解除映射
    if (munmap(addr, sb.st_size) == -1) {
        perror("munmap");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
