//http://acm.hdu.edu.cn/showproblem.php?pid=1005
#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int a = 0, b = 0, n = 0;

	scanf("%d %d %d", &a, &b, &n);
	while (a > 0 && b > 0 && n > 0)
	{
		int round[50];
		round[1] = round[2] = 1;
		//求循环的值
		int i = 3;
		for (; i <= 49; i++)
		{
			round[i] = (a * round[i - 1] + b * round[i - 2]) % 7;
			if (round[i] == 1 && round[i - 1] == 1)
				break;
		}
		int m = n % (i - 2);
		if (m == 0)
			printf("%d\n", round[i - 2]);
		else
			printf("%d\n", round[m]);
		scanf("%d %d %d", &a, &b, &n);
	}
	return 0;
}
