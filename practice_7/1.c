#include <stdlib.h>
#include <stdio.h>
void useless()
{
    printf("正在自动生成");
    int k = 3;
    while (k != 0)
    {
        Sleep(100);
        printf(".");
        k--;
    }
    printf("\n自动输入完成\n\n");
}
char *name()
{
    char *str[5] = {"jim", "tom", "peter", "lili", "susi"};
    return (str[rand() % 4]);
}
struct student
{
    int num;
    char name[30];
    int theory_score;
    char practice_score;
    enum grade
    {
        A,
        B,
        C,
        D,
        E
    } enum_var;
} stu[5];

int main()

{
    for (int i = 0; i < 5; i++)
    {
        printf("输入第%d 学生信息\n", i + 1);
        stu[i].num = (rand() % 100) + 2020000 + 100 * i;
        strcpy(stu[i].name, name());
        stu[i].theory_score = (rand() % 50 + 50);
        enum grade enum_var = rand() % 4;
        switch (enum_var)
        {

        case A:
            stu[i].practice_score = 'A';
            break;
        case B:
            stu[i].practice_score = 'B';
            break;
        case C:
            stu[i].practice_score = 'C';
            break;
        case D:
            stu[i].practice_score = 'D';
            break;
        case E:
            stu[i].practice_score = 'E';
            break;
        }
        useless();
    }

    for(int i=0;i<5;i++)
    {
        printf("第%d个学生的信息为\n",i+1);
        printf("名字:%s\n",stu[i].name);
        printf("学号:%d\n",stu[i].num);
        printf("理论课成绩:%d\n",stu[i].theory_score);
        printf("实践课成绩:%c\n\n",stu[i].practice_score);
    }

    getchar();
    getchar();
    return 0;
}