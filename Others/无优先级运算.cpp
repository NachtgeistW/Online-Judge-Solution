/*
 *      无优先级运算
问题描述：
给定n个正整数和4个运算符＋、－、*、/，且运算符无优先级，如2+3*5=25。对于任意给定的整数m，试设计一个算法，用以上给出的n个数和4个运算符，产生整数m，且用的运算次数最少。给出的n个数中每个数最多只能用1次，但每种运算符可以任意使用。

输入格式：
第1行，有2个正整数n和m。
第2行，给定的用于运算的n个正整数。

输出格式:
将计算出的产生整数m的最少无优先级运算次数以及最优无优先级运算表达式输出。
输入示例
5 25
5 2 3 6 7
2 3
1 2
输出示例
2
2+3*5
1
1+2
 */

#include<iostream>
#include<vector>
using namespace std;

int n, m, res;
//num是用来存放数字的数组
vector<int> num;
//visit是检查该数字有无被访问过的数组
vector<bool> visit;
vector<double> sum;
vector<char> oper;

int cal(const int k)
{
	double x = sum[1];
	for (int i = 1; i <= k - 1; i++)
	{
		if (oper[i] == '+') x += sum[i + 1];
		if (oper[i] == '-') x -= sum[i + 1];
		if (oper[i] == '*') x *= sum[i + 1];
		if (oper[i] == '/') x /= sum[i + 1];
	}
	return x == m;
}

bool dfs(const int x, const int step)
{
	//如果深度超过了指定的深度
	if (step > x)
	{
		if (cal(step))
		{
			res = step;
			return true;
		}
		return false;
	}

	//一个一个数字搜过去
	for (int i = 1; i <= n + 1; i++)
	{
		if (!visit[i])
		{
			sum[step + 1] = num[i];
			visit[i] = true;
			//逐个尝试这些符号可不可以
			for (int j = 1; j <= 4; j++)
			{
				if (j == 1) oper[step + 1] = '+';
				if (j == 2) oper[step + 1] = '-';
				if (j == 3) oper[step + 1] = '*';
				if (j == 4) oper[step + 1] = '/';
				if (dfs(x, step + 1)) return true;
			}
			visit[i] = false;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;
	num.resize(n + 2);
	visit.resize(n + 2);
	oper.resize(n + 2);
	sum.resize(n + 2);
	
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	int i;

	//从0开始：即一个数就能达成条件，不需要计算
	for (int j = 0; j < n; j++)
	{
		res = 0;
		if (dfs(j, 0))
		{
			cout << res - 1 << '\n';
			for(i = 1; i <= res - 1; i++)
				cout << sum[i] << oper[i];
			cout << sum[i];
			return 0;
		}
	}
	cout << "No Solution!";
	return 0;
}