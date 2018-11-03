//http://acm.hdu.edu.cn/showproblem.php?pid=1004
#include<map>
#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false);
	int N = 0;
	scanf_s("%d", &N);
	while (N != 0)
	{
		map<string, int> bal;
		for (int i = 0; i < N; i++)
		{
			string temp;
			cin >> temp;
			auto res = bal.insert({ temp, 1 });
			if (!res.second)
				++res.first->second;
		}
		string res;
		int max = 0;
		for (auto i = bal.begin(); i != bal.end(); i++)
		{
			if (i->second > max)
			{
				max = i->second;
				res = i->first;
			}
		}
		cout << res << "\n";
		scanf_s("%d", &N);
	}
	return 0;
}