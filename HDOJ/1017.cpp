//http://acm.hdu.edu.cn/showproblem.php?pid=1017
#include<iostream>
using namespace std;
int main(void)
{
    //read the number of test blocks
    int N;
    scanf("%d", &N);
    getchar();
    while(N-- > 0)
    {
        //read the num in the blocks
        for (int i = 1;;i++)
        {
			int n, m, count = 0;
			if (scanf("%d %d", &n, &m) == EOF || n == 0 && m == 0)
				break;
            for (int a = 1; a < n; a++)
                for (int b = a + 1; b < n; b++)
                {
                    int res = (((a * a) + (b * b) + m) % (a * b));
                    if (res == 0)
                        count++;
                }
            printf("Case %d: %d\n", i, count);
        }
        if(N > 0)
            putchar('\n');
    }
    return 0;
}