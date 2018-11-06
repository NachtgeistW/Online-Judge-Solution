/*http://acm.hdu.edu.cn/showproblem.php?pid=2561
Problem Description
求n个整数中倒数第二小的数。
每一个整数都独立看成一个数，比如，有三个数分别是1，1，3，那么，第二小的数就是1。
Input
输入包含多组测试数据。
输入的第一行是一个整数C，表示有C测试数据；
每组测试数据的第一行是一个整数n，表示本组测试数据有n个整数（2<=n<=10），接着一行是 n个整数 (每个数均小于100);
Output
请为每组测试数据输出第二小的整数，每组输出占一行。
Sample Input
2
2
1 2
3
1 1 3
Sample Output
2
1*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    int group, num;
    vector<int> vec;
    scanf("%d", &group);
    while(group-- > 0)
    {
        scanf("%d", &num);
        while(num-- > 0)
        {
            int i;
            scanf("%d", &i);
            vec.push_back(i);
        }
        sort(vec.begin(), vec.end());
        auto i = vec.begin() + 1;
        cout << *i << endl;
        vec.clear();
    }
}