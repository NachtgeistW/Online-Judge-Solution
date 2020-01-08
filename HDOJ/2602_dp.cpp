#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0, v = 0;
        int arr_v[1005] = { 0 }, arr_p[1005] = { 0 }, dp[1005] = { 0 };
        cin >> n >> v;
        for (int i = 1; i <= n; i++)
            cin >> arr_p[i];
        for (int i = 1; i <= n; i++)
            cin >> arr_v[i];
        for (int i = 1; i <= n; i++)
            for (int j = v; j >= arr_v[i]; j--)
                dp[j] = max(dp[j], dp[j - arr_v[i]] + arr_p[i]);
        cout << dp[v] << '\n';
    }
}
