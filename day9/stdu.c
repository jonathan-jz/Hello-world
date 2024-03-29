#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[50];
    float score;
};

int main() {
    struct student s_read[3];

    // 读取文件
    FILE *fp = fopen("students.bin", "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    if (fread(s_read, sizeof(struct student), 3, fp) != 3) {
        perror("fread");
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    // 打印读取的数据
    for (int i = 0; i < 3; i++) {
        printf("Student %d\n", i + 1);
        printf("ID: %d\n", s_read[i].id);
        printf("Name: %s\n", s_read[i].name);
        printf("Score: %.1f\n", s_read[i].score);
        printf("\n");
    }

    return 0;
}
