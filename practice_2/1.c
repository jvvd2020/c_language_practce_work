#include <stdio.h>
#include <stdlib.h>
int main()
{
    float score[4][5] = {{1001, 0, 0, 0, 0}, {1002, 0, 0, 0, 0}, {1003, 0, 0, 0, 0}, {1004, 0, 0, 0, 0}};
    int i, j;
    // void aver(float(*p)[5]);
    void aver(float *p);
    void search(float(*p)[5]);
    void sort(float(*p)[5]);

    printf("enter the grade of each student\n");
    printf("the grade has benn entered by random number\n");
    for(i = 0; i < 4; i++)
    {
        for (j = 1; j < 4; j++)
        {
            // if (j == 1 && i != 0)
            // {
            //     printf("the next student's grade\n");
            // }
            // scanf("%f", &score[i][j]);
            score[i][j] = (rand() % 40 + 1) + 60;//自动输入成绩
        }
    }
    printf("\n");
    // for (i = 0; i < 4; i++)
    // {
    //     for (j = 1; j < 4; j++)
    //     {
    //         if(j==1)
    //         printf("\n");
    //         printf(" %.1f",score[i][j]);
    //     }
    // }
    aver(*score);
    search(score);
    sort(score);

    getchar();
    getchar();
    return 0;
}

void aver(float *p)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        *(p + i*5 + 4) =(*(p + i*5 + 1) +*(p + i*5 + 2)+*(p + i*5 + 3)) /3.0;
    }
}
void search(float (*p)[5])
{
    int sear;
    int i, j;

    printf("enter the student's number you want to seach\n");
    scanf("%d", &sear);
    switch (sear)
    {
    case 1001:

        printf("math:\n");
        printf("%.1f\n", *(*(p + 0) + 1));
        printf("english:\n");
        printf("%.1f\n", *(*(p + 0) + 2));
        printf("computer:\n");
        printf("%.1f\n", *(*(p + 0) + 3));
        printf("averge:\n");
        printf("%.1f\n", *(*(p + 0) + 4));

        break;
    case 1002:
        printf("math:\n");
        printf("%.1f\n", *(*(p + 1) + 1));
        printf("english:\n");
        printf("%.1f\n", *(*(p + 1) + 2));
        printf("computer:\n");
        printf("%.1f\n", *(*(p + 1) + 3));
        printf("averge:\n");
        printf("%.1f\n", *(*(p + 1) + 4));
        break;
    case 1003:
        printf("math:\n");
        printf("%.1f\n", *(*(p + 2) + 1));
        printf("english:\n");
        printf("%.1f\n", *(*(p + 2) + 2));
        printf("computer:\n");
        printf("%.1f\n", *(*(p + 2) + 3));
        printf("averge:\n");
        printf("%.1f\n", *(*(p + 2) + 4));
        break;
    case 1004:
        printf("math:\n");
        printf("%.1f\n", *(*(p + 3) + 1));
        printf("english:\n");
        printf("%.1f\n", *(*(p + 3) + 2));
        printf("computer:\n");
        printf("%.1f\n", *(*(p + 3) + 3));
        printf("averge:\n");
        printf("%.1f\n", *(*(p + 3) + 4));
        break;
    }
}
void sort(float (*p)[5])
{
    int i, j;
    float t0,t1;
    float sorted[4][2];
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 4; i++)
        {
            if (j == 0)
                sorted[i][j] = *(*(p + i) + 4);
            else if (j == 1)
            {
                sorted[i][j] = *(*(p + i) + 0);
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3 - i; j++)
        {
            if (sorted[j][0] < sorted[j + 1][0])
            {
                t0 = sorted[j][0];
                t1 = sorted[j][1];
                sorted[j][0] = sorted[j+1][0];
                sorted[j][1] = sorted[j+1][1];
                sorted[j+1][0] = t0;
                sorted[j+1][1] = t1;
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        printf("%f\t%f\n", sorted[i][0], sorted[i][1]);
    }
}