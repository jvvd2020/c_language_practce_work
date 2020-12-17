#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N sizeof(struct Word_list)
struct Word_list
{
    char word[15];
    char exp[50];
    double fre;
};
int cal_cet_num() //计算单词量的函数 为 确定结构体数组数量
{
    FILE *fp;
    int list_num = 1;
    fp = fopen("cet.txt", "r");
    char ch;
    while (!feof(fp))
    {

        ch = fgetc(fp);
        if (ch == '\n')
        {
            list_num++;
        }
    }
    fclose(fp);
    return (list_num);
}
struct Word_list *catch;
void save()
{
    struct Word_list *p;
    p = (struct Word_list *)malloc(N * cal_cet_num());
    if (p == NULL)
    {
        printf("error\n");
        exit(0);
    }
    FILE *fp, *new;
    new = fopen("new.txt", "w");
    fp = fopen("cet.txt", "r");
    int i = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%s %s %lf", p[i].word, p[i].exp, &p[i].fre);
        printf("%s %s %lf\n", p[i].word, p[i].exp, p[i].fre);
        fprintf(new, "%s\t%s\t%lf\n", p[i].word, p[i].exp, p[i].fre);
        i++;
    }
    fclose(fp);
    fclose(new);
    catch = p;
}
void search()
{
    printf("输入一个要查询的单词\n");
    char search[15];

    gets(search);
    for (int i = 0; i < cal_cet_num(); i++)
    {
        if (strcmp(search, catch[i].word) == 0)
        {
            puts(catch[i].exp);
            break;
        }
        if(i == cal_cet_num()-1)
        {
            printf("没有这个单词\n");
        }
    }
    printf("输入一个频率\n");
    double number;
    scanf("%lf", &number);
    for (int i = 0; i < cal_cet_num(); i++)
    {
        if (number<catch[i].fre)
        {
            puts(catch[i].word);
        }
    }
}
int main()
{
    save();
    search();
    getchar();
    getchar();
    return 0;
}