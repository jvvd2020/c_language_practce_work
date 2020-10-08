#include<stdio.h>
#include <stdlib.h>
int main()
{
    void sort(int *p);
    int array[10];
    int i;
    for(i=0;i<10;i++)
    {
        *(array+i)=rand()%100;
    }
    printf("the content of the array is:\n");
      for(i=0;i<10;i++)
    {
        printf("%d\n",*(array+i));
    }
    sort(array);
    printf("the content of the sorted array is:\n");
    for(i=0;i<10;i++)
    {
        printf("%d\n",*(array+i));
    }


    getchar();
    getchar();
    return 0;
}

void sort(int *p)
{
    int i,j,t;
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<=9;j++)
        {
            if(*(p+i) < *(p+j))
            {
                t = *(p+j);
                *(p+j) = *(p+i);
                *(p+i) = t;
            }
        }
    }
}