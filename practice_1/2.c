#include<stdio.h>
int main()
{
    void reverse(int *p);
    int a[5];
    int i;
    int *p = a;
    printf("input the five numbers\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",p++);
    }
    printf("the original sequence is\n");
    for(p=a,i=0;i<5;i++)
    {
        printf("%d\n",*p++);
    }
    p=a;
    reverse(p);
    printf("the sorted sequence is:\n");
    for(i=0;i<5;i++)
    {
        printf("%d\n",*(a+i));
    }
    getchar();
    getchar();
    return 0;
}
void reverse(int *p)
{
    int i,j,t;
    for(i=0,j=4;i<3;i++,j--)
    {   
        t = *(p+i);
        *(p+i) = *(p+j);
        *(p+j) = t;
    }
}