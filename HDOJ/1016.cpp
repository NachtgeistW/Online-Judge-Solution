//http://acm.hdu.edu.cn/showproblem.php?pid=1016
#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<int>& vec, vector<bool>& visit, unsigned int step);
const static int prime_length = 100;
//素数判断数组
bool prime[prime_length];
//总数
unsigned int n;

struct node
{
	int num;
	node* left;
	node* right;
};

int main()
{
	int i, k = 1;
	prime[2] = true;
	for (i = 3; i < prime_length; i++)
		if (i % 2) prime[i] = true;
		else prime[i] = false;
	for (i = 3; i <= sqrt(prime_length); i++)
	{
		if (prime[i])
			for (int j = i + i; j < prime_length; j += i)
				prime[j] = false;
	}

	vector<int> vec;
	vector<bool>visit;
	while (cin >> n)
	{
		cout << "Case " << k << ":\n";
		//因为0是用不上的，所以得多开一个
		visit.resize(n + 1, false);
		vec.resize(n + 1, 0);
		visit.at(1) = true;
		vec.at(1) = 1;
		dfs(vec, visit, 1);
		cout << '\n';
		k++;
	}
	return 0;
}

void dfs(vector<int>& vec, vector<bool>& visit, const unsigned int step)
{
	//如果已经到最后一步了
	if (step == n && prime[1 + vec[n]])
	{
		for (size_t i = 1; i < vec.size(); i++)
		{
			cout << vec.at(i) << (i < n ? ' ' : '\n');
		}
		return;
	}

	//没有
	for (size_t i = 2; i <= n; i++)
	{
		if (!visit[i] && prime[vec[step] + i])
		{
			vec[step + 1] = i;
			visit[i] = true;
			dfs(vec, visit, step + 1);
			visit[i] = false;
		}
	}
}
