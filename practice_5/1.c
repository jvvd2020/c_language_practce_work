#include <stdio.h>
#include <stdlib.h>
struct Student
{
    int num;
    char name[20];
    int math;
    int english;
    int chinese;
    float average;
} stu[3];
struct Student *p[3];
void input();
void output();
void output_sorted();
void print_single_student(int i);
int _max();
void sort();
float avr();

int main()
{
    input();
    output();
    printf("the highest score student is stusent[%d]\n", _max());
    print_single_student(_max());
    printf("the total average is :%.2f\n", avr());
    sort();
    output_sorted();

    getchar();
    getchar();
    return 0;
}
void input()
{
    int i, temp;
    for (i = 0; i < 3; i++)
    {
        printf("enter the number of student[%d]\n", i);
        printf("%d\n", i);
        stu[i].num = i;
        printf("enter the name of student[%d]\n", i);
        printf("%c\n", 97 + i);
        stu[i].name[0] = 97 + i;
        printf("enter the grade of math\n");
        temp = rand() % 40 + 60;
        printf("%d\n", temp);
        stu[i].math = temp;
        printf("enter the grade of english\n");
        temp = rand() % 40 + 60;
        printf("%d\n", temp);
        stu[i].english = temp;
        printf("enter the grade of chinese\n");
        temp = rand() % 40 + 60;
        printf("%d\n", temp);
        stu[i].chinese = temp;
        printf("\n\n\n");
        stu[i].average = (stu[i].math + stu[i].english + stu[i].chinese) / 3.0;
    }
}
void output()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        print_single_student(i);
    }
}

void output_sorted()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        print_single_student(p[i]->num);
    }
}

int _max()
{
    int highest = stu[0].math;
    int i = 0;
    int flag;
    for (i = 0; i < 3; i++)
    {
        if (highest < stu[i].math)
        {
            highest = stu[i].math;
            flag = i;
        }
        else if (highest < stu[i].english)
        {
            highest = stu[i].english;
            flag = i;
        }
        else if (highest < stu[i].chinese)
        {
            highest = stu[i].chinese;
            flag = i;
        }
    }
    return flag;
}
void print_single_student(int i)

{
    printf("the number of student[%d]:\n%d\n", i, stu[i].num);
    printf("the name of student of student[%d]:\n%s\n", i, stu[i].name);
    printf("the grade of math:\n%d\n", stu[i].math);
    printf("the grade of english:\n%d\n", stu[i].english);
    printf("the grade of chiese:\n%d\n", stu[i].chinese);
    printf("the average of student[%d]:\n%.2f\n", i, stu[i].average);
    printf("\n\n\n");
}

float avr()
{
    return ((stu[0].average + stu[1].average + stu[2].average) / 3.0);
}

void sort()
{
    int i, j;
    int max;
    struct Student *t;
    for (i = 0; i < 3; i++)
    {
        p[i] = stu + i;
    }
    for (i = 0; i < 2; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            if ((*p[i]).average < (*p[j]).average)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}
