#include <stdio.h>
#include <stdlib.h>
#define N 20
int main()
{
    char string[N];
    char t;
    char *a;
    FILE *fp;
    printf("input the string\n");
    gets(string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        for (int j = i + 1; string[j] != '\0'; j++)
        {
            if (string[i] < string[j])
            {
                t = string[i];
                string[i] = string[j];
                string[j] = t;
            }
        }
    }
    if ((fp = fopen(".\\string", "w")) == NULL)
    {
        printf("文件创建失败\n");
        exit(0);
    }
    if ((fputs(string, fp)) != 0)
    {
        printf("文件写入失败\n");
        exit(0);
    }
    else
    {
        fclose(fp);
        if ((fp = fopen(".\\string", "r")) == NULL)
        {
            printf("文件打开失败\n");
            exit(0);
        }
        printf("排序后的的字符\n");
        if ((a = fgets(string, N, fp)) == NULL)
        {
            printf("读取失败\n");
            exit(0);
        }
        else
        {
            puts(a);
        }
        fclose(fp);
    }

    getchar();
    getchar();
    return 0;
}
