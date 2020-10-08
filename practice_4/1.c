#include <stdio.h>
#include <stdlib.h>
char *name[8]={    "alpha1",
                    "betty2",
                    "candy3",
                    "duck4",
                   "2220190001","2220190002","2220190003","2220190004"};
int main()
{
    int strcmp(char *p1, char *p2);
    int *fail(int (*score)[3]);
    int score[4][3];
    int strcmp(char *p1,char *p2);
    char s1[50];
    char s2[50]; 
    int i, j;
        

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            score[i][j] = (rand() % 40 + 1) + 55; //自动输入成绩
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            
            printf("%d ",score[i][j]);
            if(j==2)
            {
                printf("\n");
            }
        }
    }
    for(i=0;i<4;i++)
    
    {
        if( *(fail(score)+i) != 9 )
        {
            printf("the failed student's name is %s\n the number is %s\n",name[i],name[i+4]);
        }
    }
    char *pointer_pointer[4] = { "alpha1",
                                "betty2",
                                "candy3",
                                "duck4"};
    char *t;
    for(i=0;i<3;i++)
    {
        for(j=i;j < 3;j++)
        {
            if(strcmp(pointer_pointer[j],pointer_pointer[j+1]) > 0)
            {
                t = pointer_pointer[j+i];
                pointer_pointer[j+1] = pointer_pointer[j];
                pointer_pointer[i] = t;
            }
        }
    }
    printf("the sequence of name is\n");
    for(i=0;i<4;i++)
    {
        printf("%s\n",*(pointer_pointer+i));
    }



    getchar();
    getchar();
    return 0;
}
int *fail(int (*score)[3])
{
    int i,j;
    
    static int fail_stu[4]={9,9,9,9};
    for(i=0;i<4;i++)
    {
        for(j=0;j<3;j++)
        {
            if(  *(*(score+i)+j)  < 60 )
            {
                fail_stu[i] = i;
                break;         
            }
        }
    }
    return(fail_stu);
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

