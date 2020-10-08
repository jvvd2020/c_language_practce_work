/*2．写一个函数，实现两个字符串的比较。即自己写一个strcmp函数，函数原型为
int strcmp(char *p1, char *p2);
设p1指向字符串s1，p2指向字符串s2。要求当s1=s2时，返回值为0；
若s1≠s2，返回他们二者第一个不同字符的ASCII码差值。
如果s1＞s2，输出正值；如果s1＜s2，输出负值。*/
#include <stdio.h>
int main()
{
    char s1[50]; //= "12345";
    char s2[50]; //= "12345";
    int i;
    while (1)
    {
        printf("enter the s1 string\n");
        gets(s1);
        printf("enter the s2 string\n");
        gets(s2);
        int strcmp(char *p1, char *p2);
        printf("the result is %d\n\n", strcmp(s1, s2));
    }
    getchar();
    getchar();
    return 0;
}
int strcmp(char *p1, char *p2)
{
    int i;
    int flag;
    for (i = 0; (*(p1 + i) != '\0') || (*(p2 + i) != '\0'); i++)
    {
        if (*(p1 + i) - *(p2 + i) == 0)
        {
            flag = 0;
            continue;
        }
        else if (*(p1 + i) - *(p2 + i) < 0)
        {
            flag = *(p1 + i) - *(p2 + i);
            return flag;
            break;
        }
        else if (*(p1 + i) - *(p2 + i) > 0)
        {
            flag = *(p1 + i) - *(p2 + i);
            return flag;
            break;
        }
    }
    return flag;
}