//2709
#include <iostream>
using namespace std;

int a[1000001];
/*
 * https://blog.csdn.net/lianai911/article/details/44937005
 * 偶数：a[n] = a[n/2] + a[n - 2]
 * n - 2：eg: 4 2+2, 4
 * 奇数：a[n] = a[n - 1]
 */
int main()
{
	ios::sync_with_stdio(false);
	a[1] = 1;
	a[2] = 2;
	int i = 3;
	while (i <= 1000000)
	{
		a[i] = a[i - 1];
		i++;
		//保留最后九位
		a[i] = (a[i - 2] + a[i >> 1]) % 1000000000;
		i++;
	}
	int n;
	while(cin >> n)
		cout << a[n] << '\n';
	return 0;
}
