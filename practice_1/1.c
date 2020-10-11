//v3
#include<stdio.h>
int main()
{
    int a, b, c;
    int compare(int,int);
    printf("input three numbers to compare\n");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    printf("the max number is %d\n",compare(a,compare(b,c)));
    getchar();
    getchar();
    return 0;
}
int compare(int var1,int var2)
{
    if(var1>var2)
    {
        return(var1);
    }
    else
    {
        return(var2);
    }
}
