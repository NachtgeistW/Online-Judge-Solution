//http://acm.hdu.edu.cn/showproblem.php?pid=2019
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void)
{
	std::ios::sync_with_stdio(false);
	int n, m;
	vector<int> vec;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		vec.push_back(m);
		int temp;
		for(int i = 0; i < n; i++)
		{
			cin >> temp;
			vec.push_back(temp);
		}
		sort(vec.begin(), vec.end());
		for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			
			if (it == vec.begin())
				cout << *it;
			else
				cout << ' ' << *it; 
		}
		cout << '\n';
		vec.clear();
	}
}
