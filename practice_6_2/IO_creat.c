#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct Student)+20*sizeof(char)
struct Student
{
    int num;
    int math;
    int chinese;
    int english;
    float average;
    struct Student *next;
    char name[]; //柔性数组
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
        exit(0);
        // return (head);
        head = NULL;
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

void sort()
{
    printf("\n链表排序开始\n");
    struct Student *porter, *porter_next; //定义从无序链表里取新成员的指针,和服务于该指针的指针
    if (head == NULL)
    {
        return;
    }
    //第一步:将链表头节点拆下来
    porter = head->next;
    head->next = NULL;
    //第二步:判断是否只有一个head
    if (porter == NULL)
    {
        return;
    }
    //第三步:组建最初的有序链表 在组建之前首先要将porter的下一个节点保存
    porter_next = porter->next;          //-------------储存
    if (porter->average > head->average) // porter的data 大于 head的data 互换
    {
        porter->next = head; //新head的next成员指向旧head
        head = porter;       //更换新head
    }
    else //head 还是原来的head
    {
        head->next = porter;
        porter->next = NULL;
    }
    //过渡阶段
    porter = porter_next; //porter指针指向新一个无序链表的第一个节点,即为之前porter_next所保存的 <<<<<<<<<<<<使用
    //准备阶段结束,开始插入
    while (porter != NULL) //无序链表不为空
    {
        porter_next = porter->next; //再次储备porter的下一个节点 --------储存
        //准备有序链表的指针
        struct Student *order_current, *order_prev; //在有序链表里使用的指针
        order_current = head;                       //定义开始比较的头
        //开始遍历比较
        while (order_current != NULL && (order_current->average >= porter->average))
        {
            order_prev = order_current;          //比较完之后,current指针已经成为上一个了
            order_current = order_current->next; //开始使用下一个有序链表中的成员
        }
        //分情况讨论
        if (order_current == NULL) // 排到有序链表最后
        {
            order_prev->next = porter; //让porter作为有序链表的最后一个元素
            porter->next = NULL;
        }
        else if (order_current == head) //porter元素成为新的head
        {
            porter->next = head;
            head = porter;
        }
        else //在中间的情况
        {
            order_prev->next = porter;
            porter->next = order_current;
        }
        //排序完成
        //porter更新
        porter = porter_next; //<<<<<<<<<<<<<<<使用
    }
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

void delete ()
{
    printf("\n删除学生函数开始\n");
    int num_to_delete;
    struct Student *pt_del, *pt_prev;
    pt_del = head;
    printf("输入待要删除学生的学号\n");
    scanf("%d", &num_to_delete);
    if (num_to_delete == head->num)
    {
        head = head->next;
        free(pt_del);
        printf("删除成功\n");
        return;
    }
    while ((pt_del != NULL) && (pt_del->num != num_to_delete)) //一定要有最后一个指针为空不然就会一直循环
    {
        pt_prev = pt_del;
        pt_del = pt_del->next;
    }
    if (pt_del == NULL)
    {
        printf("没有这个同学\n");
        return;
    }
    pt_prev->next = pt_del->next;
    free(pt_del);
    printf("删除成功\n");
}