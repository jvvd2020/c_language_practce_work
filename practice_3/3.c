/*3．用指向函数的指针实现下述代码：
从主函数中输入两个整数，然后让用户选择1或者2，
选择1的时候，求出两个整数的最大公约数；
选择2的时候，求出两个整数的最小公倍数。*/
#include <stdio.h>
int main()
{
    int a, b;
    int m;
    int (*p)(int, int);
    int max(int a, int b);
    int min(int a,int b);
    printf("enter a\n");
    scanf("%d", &a);
    printf("enter b\n");
    scanf("%d", &b);
    printf("enter 1 to calculate the greatest common divisor,\
    enter 2 to calculate the Least Common Multiple\n");
    scanf("%d", &m);
    if (m == 1)
    {
        p = max;
        printf("the greatest common divisor is %d", (*p)(a, b));
    }
    else if (m == 2)
    {
        p = min;
        printf("the the Least Common Multiple is %d", (*p)(a, b));
    }

    getchar();
    getchar();
    return 0;
}
int max(int a, int b)
{
    if (a == b)
    {
        return a;
    }
    else if (a > b)
    {
        a = a - b;
    }
    else if (a < b)
    {
        b = b - a;
    }
    return (max(a, b));
}
int min(int a, int b)
{
    return a * b / max(a, b);
}