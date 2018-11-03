//http://acm.hdu.edu.cn/showproblem.php?pid=2026
#include<iostream>
#include<string>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    string str;
    while(getline(cin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (i == 0 || str[i - 1] == ' ')
            str[i] = toupper(str[i]);
        }
        cout << str << "\n";
    }
    return 0;
}