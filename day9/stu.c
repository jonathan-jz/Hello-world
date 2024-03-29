#include<func.h>

struct student {
    int id;
    char name[50];
    float score;
};

int main(int argc,char*argv[]){

    struct student s[3] = {
        {1, "Alice", 95.5},
        {2, "Bob", 88.0},
        {3, "Charlie", 78.5}
    };
    // 打开文件
    int fd = open("students.dat", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // 将数据写入文件
    if (write(fd, s, sizeof(s)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // 偏移到文件开头
    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("lseek");
        exit(EXIT_FAILURE);
    }

    // 读取并打印数据
    struct student s_read[3];
    if (read(fd, s_read, sizeof(s_read)) == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 3; i++) {
        printf("Student %d\n", i + 1);
        printf("ID: %d\n", s_read[i].id);
        printf("Name: %s\n", s_read[i].name);
        printf("Score: %.1f\n", s_read[i].score);
        printf("\n");
    }

    // 关闭文件
    close(fd);

    return 0;
}