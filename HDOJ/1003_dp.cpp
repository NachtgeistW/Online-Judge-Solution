//http://acm.hdu.edu.cn/showproblem.php?pid=1003

#include <iostream>
#include <vector>
using namespace std;
vector<int>dp;

int main()
{
	ios::sync_with_stdio(false);
	size_t n;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		size_t length;
		cin >> length;
		for (size_t j = 0; j < length; j++)
		{
			int temp;
			cin >> temp;
			dp.push_back(temp);
		}

		const size_t l = dp.size();
		size_t left = 0, right = 0, temp_l = 0;//游标
		int max = dp.front();

		//状态转移方程：dp[k] = max(dp[k - 1] + dp[k], dp[k])
		for (size_t k = 1; k < l; k++)
		{
			//如果dp[k - 1]大于等于0，则对子序列和有贡献，可以加上
			if (dp.at(k - 1) >= 0)
				dp[k] = dp[k - 1] + dp[k];
			//没有贡献，重置临时游标
			else
				temp_l = k;
			if (max < dp.at(k))
			{
				max = dp.at(k);
				left = temp_l;
				right = k;
			}
		}

		cout << "Case " << i + 1 << ":\n";
		cout << max << ' ' << left + 1 << ' ' << right + 1 << '\n';
		if (i < n - 1)
			cout << '\n';
		dp.clear();
	}
}
