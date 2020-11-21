#include <stdio.h>
int fun1(int n)
{
    if (n == 0)
        return 1;
    n = n * fun1(n - 1);
    return n;
}
int main()
{
    printf("%d\n",fun1(5));
    getchar();
    getchar();
}