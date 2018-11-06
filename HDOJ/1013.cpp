/*http://acm.hdu.edu.cn/showproblem.php?pid=1013*/
#include<iostream>
#include<string>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    string num;
    while(cin >> num && num != "0")
    {
        int t = 0;
        while(1)
        {
            for (int i = 0; i < num.size(); i++)
                t += num[i] - '0';

            if (t >= 0 && t <= 9)
                break;
            else
                {
                    num = to_string(t);
                    t = 0;
                }
        }
        printf("%d\n", t);
    }
    return 0;
}