#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)
struct Student
{
    int num;
    int math;
    int chinese;
    int english;
    float average;
    struct Student *next;
    char name[20]; //柔性数组,在之后交换的时候并不适合
};
struct Student *head, *p_present, *p_open;
float n = 0;
void enter_creat()
{
    printf("输入学号\n");
    scanf("%d", &p_open->num);
    if (p_open->num == 0)
    {
        return;
    }
    printf("输入学生名字\n");
    scanf("%s", p_open->name);
    printf("输入数学成绩\n");
    scanf("%d", &p_open->math);
    printf("输入语文成绩\n");
    scanf("%d", &p_open->chinese);
    printf("输入英语成绩\n");
    scanf("%d", &p_open->english);
    p_open->average = (p_open->math + p_open->chinese + p_open->english) / 3.0;
}
struct Student *creat() //创建链表函数
{
    p_present = p_open = (struct Student *)malloc(LEN);
    if (p_present == NULL)
    {
        printf("分配内存失败\n");
        printf("回车退出\n");
        getchar();
        getchar();
        exit(0);
    }
    enter_creat(); //输入部分
    n++;           //第一次计人数
    if (p_present->num == 0)
    {
        n--;
        head = NULL;
        exit(0);
        // return (head);
    }
    head = p_present;
    while (p_open->num != 0)
    {
        p_present->next = p_open; //指向下一个节点
        p_present = p_open;       //将操作对象移动至下一个节点
        p_open = (struct Student *)malloc(LEN);
        if (p_open == NULL)
        {
            printf("分配内存失败\n");
            printf("回车退出\n");
            getchar();
            getchar();
            exit(0);
        }
        enter_creat(); //输入部分
        n++;           //第二次计数
    }
    n--; //去除最后一次0的计数
    p_present->next = NULL;
    printf("创建数组函数运行结束\n\n");
    return (head);
}
void output_creat(struct Student *pt) //输出链表函数
{
    while (pt != NULL)
    {
        printf("学号:%d\n", pt->num);
        printf("姓名:%s\n", pt->name);
        printf("数学:%d\n", pt->math);
        printf("语文:%d\n", pt->chinese);
        printf("英语:%d\n", pt->english);
        printf("平均分:%.1f\n\n", pt->average);
        pt = pt->next;
    }
    printf("\n输出链表函数运行结束\n");
}
float avr() //平均数函数
{
    if (head == NULL)
    {
        return 0;
    }
    long int total = 0;
    struct Student *pt;
    pt = head;
    while (pt != NULL)
    {
        total = total + pt->average;
        pt = pt->next;
    }
    printf("共有%d个人", (int)n);
    printf("总平均成绩为%.1f\n", total / n);
    printf("求平均数函数运行结束\n\n");
}
void IO_creat() //调用"创建链表函数"和"输出链表函数"
{
    output_creat(creat());
}


void _max()
{
    if (head == NULL)
    {
        return;
    }
    struct Student *pt;
    struct Student *max_one;
    int subject = 1;
    max_one = pt = head;
    int max = pt->math;
    while (pt != NULL)
    {
        if (pt->math > max)
        {
            max = pt->math;
            max_one = pt;
            subject = 1;
        }
        if (pt->chinese > max)
        {
            max = pt->chinese;
            max_one = pt;
            subject = 2;
        }
        if (pt->english > max)
        {
            max = pt->english;
            max_one = pt;
            subject = 3;
        }
        pt = pt->next;
    }
    printf("单科成绩最高的学生是%s\n", max_one->name);
    printf("他的");
    switch (subject)
    {
    case 1:
        printf("数学");
        break;
    case 2:
        printf("语文");
        break;
    case 3:
        printf("英语");
        break;
    default:
        break;
    }
    printf("成绩最高,为%d分\n", max);
    printf("求单科最高成绩函数结束\n\n");
}

void search()
{
    printf("\n查询学生函数开始\n");
    int num;
    struct Student *pt;
    pt = head;
    printf("输入待查询学号\n");
    scanf("%d", &num);
    while (pt != NULL)
    {
        if (num == pt->num)
        {
            printf("学号:%d\n", pt->num);
            printf("姓名:%s\n", pt->name);
            printf("数学:%d\n", pt->math);
            printf("语文:%d\n", pt->chinese);
            printf("英语:%d\n", pt->english);
            printf("平均分:%.1f\n", pt->average);
            printf("查询学生函数结束\n\n");
            return;
        }
        pt = pt->next;
    }
}

void sort() //1.柔性数组在赋值时的问题,字符问题,本身是不确定大小的,在开辟数组时如何确定大小 问题
{
    printf("\n链表排序开始\n");
    if (head == NULL)
    {
        return;
    }
    struct Student *p, *pt = head;
    struct Student temp;
    p = (struct Student *)malloc(n * LEN); //1.柔性数组在赋值时的问题,字符问题,本身是不确定大小的,在开辟数组时如何确定大小 问题
    if (p == NULL)
    {
        printf("内存分配失败\n");
        return;
    }
    for (int i = 0; i <= n - 1; i++)
    {
        p[i].num = pt->num;
        strcpy(p[i].name, pt->name);
        p[i].math = pt->math;
        p[i].chinese = pt->chinese;
        p[i].english = pt->english;
        p[i].average = pt->average;
        p[i].next = pt;
        pt = pt->next;
    }
    for (int i = 0, j; i <= n - 2; i++)
    {
        for (j = i; j < n - 1; j++)
        {
            if ((p + i)->num < p[j + 1].num)
            {
                temp = p[i];
                p[i] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    head = p[0].next;
    pt = head;
    for (int i = 0; i <= n - 1; i++)
    {
        pt->num = p[i].num;
        strcpy(pt->name, p[i].name);
        pt->math = p[i].math;
        pt->chinese = p[i].chinese;
        pt->english = p[i].english;
        pt->average = p[i].average;
        if (i == n - 1)
        {
            pt->next = NULL;
            break;
        }
        pt->next = p[i + 1].next;
        pt = pt->next;
    }
    // printf("排序后的顺序\n");
    // output_creat(head);
    free(p);
    printf("\n链表排序结束\n\n");
}
void insert()
{
    printf("\n插入函数开始\n");
    n++;
    struct Student *p_insert;
    p_insert = (struct Student *)malloc(LEN);
    printf("输入学生信息\n");
    printf("输入学号\n");
    scanf("%d", &p_insert->num);
    printf("输入学生名字\n");
    scanf("%s", p_insert->name);
    printf("输入数学成绩\n");
    scanf("%d", &p_insert->math);
    printf("输入语文成绩\n");
    scanf("%d", &p_insert->chinese);
    printf("输入英语成绩\n");
    scanf("%d", &p_insert->english);
    p_insert->average = (p_insert->math + p_insert->chinese + p_insert->english) / 3.0;
    p_insert->next = head;
    head = p_insert;
    printf("插入函数结束\n\n");
}
void reput()
{
    printf("\n重新输出新的链表\n");
    output_creat(head);
}


void delete()
{
    printf("\n删除学生函数开始\n");
    int num_to_delete;
    struct Student *pt,*last;
    pt = head;
    printf("输入待要删除学生的学号\n");
    scanf("%d", &num_to_delete);
    if(num_to_delete == head->num)
    {
        head = head->next;
        free(pt);
        printf("删除成功\n");
        return;
    }
    while (pt != NULL)
    {
        if (num_to_delete == pt->num)
        {
            last = head;
            while(last != NULL)
            {
                if(last->next == pt)
                {
                    last->next = pt->next;
                    free(pt);
                    printf("删除成功\n");
                    return;
                }
                last = last->next;
            }
        }
        pt = pt->next;
    }
}