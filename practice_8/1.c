#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu_info
{
    int english;
    int chinese;
    int math;
    char name[20];
    float average;
} stu[5];
char *name()
{
    char *str[5] = {"jim", "tom", "peter", "lili", "susi"};
    return (str[rand() % 4]);
}
void sort()
{
    float t;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (stu[i].average < stu[j].average)
            {
                t = stu[i].average;
                stu[i].average = stu[j].average;
                stu[j].average = t;
            }
        }
    }
}
void put_stu_info()
{
    for (int i = 0; i < 5; i++)
    {
        printf("\n");
        puts(stu[i].name);

        printf("数学成绩:%d\n", stu[i].math);

        printf("语文成绩:%d\n", stu[i].chinese);

        printf("英语成绩:%d\n", stu[i].english);

        printf("平均成绩:%.1f\n", stu[i].average);
    }
}
void input_stu_info()
{
    for (int i = 0; i < 5; i++)
    {
        printf("输入学生名字\n");
        strcpy(stu[i].name, name());
        puts(stu[i].name);

        printf("输入数学成绩\n");
        stu[i].math = rand() % 50 + 50;
        printf("%d\n", stu[i].math);

        printf("输入语文成绩\n");
        stu[i].chinese = rand() % 50 + 50;
        printf("%d\n", stu[i].chinese);

        printf("输入英语成绩\n");
        stu[i].english = rand() % 50 + 50;
        printf("%d\n", stu[i].english);

        stu[i].average = (stu[i].chinese + stu[i].english + stu[i].math) / 3.0;
    }
}
void save_stu_info()
{
    FILE *fp;
    if ((fp = fopen("stu_info", "wb")) == NULL)
    {
        printf("文件创建失败\n");
        return;
    }
    for (int i = 0; i < 5; i++)
    {
        if ((fwrite(&stu[i], sizeof(struct stu_info), 1, fp)) != 1)
        {
            printf("文件写入错误\n");
            return;
        }
    }
    fclose(fp);
}
void read_stu_info()
{
    FILE *fp;

    fp = fopen("stu_info", "rb");
    for (int i = 0; i < 5; i++) //存入原数组
    {
        if (fread(&stu[i], sizeof(struct stu_info), 1, fp) != 1)
        {
            printf("error\n");
            exit(0);
        }
    }
    fclose(fp);
}

int main()
{
    input_stu_info();
    save_stu_info();
    read_stu_info();
    sort();
    put_stu_info();
    getchar();
    getchar();
    return 0;
}