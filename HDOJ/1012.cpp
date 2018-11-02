//http://acm.hdu.edu.cn/showproblem.php?pid=1012
#include<stdio.h>
double curE(int num);

int main(void) 
{
    printf("n e\n");
    printf("- -----------\n");
    for (int i = 0; i <= 9; i++)
    {
        double res = 0;
        for (int j = 0; j <= i; j++)
        {
            res += 1 / curE(j);
        }
        if (i == 0 || i == 1)
            printf("%d %.0f\n", i, res);
        else if (i == 2)
            printf("%d %.1f\n", i, res);
        else
            printf("%d %.9f\n", i, res);
    }
}

double curE(int num)
{
    double result = 1;
    if (num == 0 || num == 1)
    {
        result = 1;
    }
    else
    {
        for (int i = 1; i <= num; i++)
        {
            result *= i;
        }
    }
    return result;
}