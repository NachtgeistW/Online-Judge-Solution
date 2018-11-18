//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1917
#include<iostream>
using namespace std;
int main(void)
{
	double a = 0, b = 0;
	int k = 0;
	while (cin >> k)
	{
		int count = 0;
		int x[10000], y[10000];
		for (b = k; b <= k * 2; b++)
		{
			a = k * b / (b - k);
			if (a >= b && a == (int)a)
			{
				x[count] = (int)a;
				y[count] = b;
				count++;
			}
		}
		printf("%d\n", count);
		for (int i = 0; i < count; i++)
		{
			printf("1/%d = 1/%d + 1/%d\n", k, x[i], y[i]);
		}
	}
	return 0;
}