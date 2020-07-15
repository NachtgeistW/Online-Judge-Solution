//http://acm.hdu.edu.cn/showproblem.php?pid=1049
//直接模拟虫子爬的过程
#include<cstdio>
int main(void)
{
    int n = 0, u = 0, d = 0;
    while(scanf("%d %d %d", &n, &u, &d) && n != 0)
    {
        int time = 0, dist = 0;
        while(1)
        {
            dist += u;
            time++;
            if (dist >= n)
                break;
            dist -= d;
            time++;
        }
        printf("%d\n", time);
    }
    return 0;
}
