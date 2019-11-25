/*
 * Problem Description
Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.


Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).


Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.


Sample Input
3
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
5 -3 -2 -1 -2 -3

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6

Case 3:
-1 3 3
 */

#include <iostream>
#include <vector>
using namespace std;
vector<int>input;

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
			input.push_back(temp);
		}
		
		const size_t l = input.size();
		size_t left = 0, right = 0, temp_l = 0;//游标
		int max = input.front(), sum = 0;
		for (size_t k = 0; k < l; k++)
		{
			sum += input.at(k);
			if (max < sum)
			{
				max = sum;
				left = temp_l;
				right = k;
			}
			if (sum < 0)
			{
				sum = 0;
				//如果总和小于0，说明当前的数值只会越加越小，不如直接往前移。
				temp_l = k + 1;
			}
		}
		cout << "Case " << i + 1 << ":\n";
		cout << max << ' ' << left + 1 << ' ' << right + 1 << '\n';
		if (i < n - 1)
			cout << '\n';
		input.clear();
	}
}
