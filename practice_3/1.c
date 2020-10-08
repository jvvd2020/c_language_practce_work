/*1．有一个字符串，包含n个字符。写一个函数，
将此字符串中从第m个字符开始的全部字符复制成另一个字符串*/
#include <stdio.h>
int main()
{
    char string[] = "123456789";
    int m;
    void copy(char *p, int m);
    printf("enter a m\n");
    scanf("%d", &m);
    copy(string, m);

    getchar();
    getchar();
    return 0;
}

void copy(char *p, int m)
{
    char another[50];
    int i;
    for(i=0;*(p+m-1) != '\0';i++,p++)
    {
        another[i] = *(p+m-1);
    }
    another[i] = '\0';
    printf("%s\n",another);
}