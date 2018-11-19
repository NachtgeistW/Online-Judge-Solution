//http://acm.hdu.edu.cn/showproblem.php?pid=1022
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int main(void)
{
    int N;
    while (cin >> N)
    {
        char o1[1000], o2[1000];
        stack<int> stk;
        cin >> (o1 + 1) >> (o2 + 1);
        //用来存放指定的进栈序列
        for (int i = 1; i <= N; i++)
        {
            o1[i] -= '0';
        }
        //用来存放指定的出栈序列
        for (int i = 1; i <= N; i++)
        {
            o2[i] -= '0';
        }

        bool ok = true;
        int in = 1, out = 1;
        vector<string> action;
        //当火车没有全出来之前
        while (out <= N)
        {
            //如果进栈的和指定出栈的火车序列是同一辆，那么直接开过去
            if (o2[out] == o1[in])
            {
                in++;
                out++;
                action.push_back("in");
                action.push_back("out");
            }
            //如果栈顶的火车是指定要出栈的，那么弹出栈顶
            else if (!stk.empty() && stk.top() == o2[out])
            {
                stk.pop();
                out++;
                action.push_back("out");
            }
            //如果不符合以上两种情况，但是还有车等待进栈，那么进栈（怀疑有10）
            else if (in <= N && o1[in] <= N)
            {
                stk.push(o1[in]);
                in++;
                action.push_back("in");
            }
            //如果不符合以上所有条件，则直接判失败
            else
            {
                ok = false;
                action.clear();
                break;
            }
        }
        printf("%s.\n", ok ? "Yes" : "No");
        if (ok && !action.empty())
            for (auto i = action.begin(); i != action.end(); i++)
                printf("%s\n", i->c_str());
        printf("FINISH\n");
    }
    return 0;
}