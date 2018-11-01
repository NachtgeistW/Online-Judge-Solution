//http://acm.hdu.edu.cn/showproblem.php?pid=1002
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(void)
{
    int Case = 0;
    cin >> Case;
    static char input1[1001], input2[1001];
    for (int a = 1; a <= Case; a++)
    {
        if (a > 1)
            printf("\n\n");

        //读取数字
        cin >> input1 >> input2;

        //初始化三个数组
        int num1[1001], num2[1001], result[1001];
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        memset(result, 0, sizeof(result));
        
        //求最大字符长度
        int nmax = max(strlen(input1), strlen(input2));

        //逆序赋值
        int j1 = 0, j2 = 0;
        for (int i = strlen(input1) - 1; i >= 0; i--)
            num1[j1++] = input1[i] - '0';
        for (int i = strlen(input2) - 1; i >= 0; i--)
            num2[j2++] = input2[i] - '0';

        //对应位数相加
        for(int i = 0; i < nmax; i++)
            result[i] = num1[i] + num2[i];
        
        //如果有进位
        for(int i = 0; i < nmax; i++)
        {
            if (result[i] >= 10)
            {
                //下一位+1
                result[i+1] += 1;
                result[i] %= 10;
            }
        }

        //打印
        cout << "Case " << a << ":" << endl;
        for (int i = strlen(input1) - 1; i >=0; i--)
            printf("%d", num1[i]);
        printf(" + ");
        for (int i = strlen(input2) - 1; i >=0; i--)
            printf("%d", num2[i]);
        printf(" = ");    
        if (result[nmax] == 0)
        {
            for (int i = nmax - 1; i >=0; i--)
                printf("%d", result[i]);
        }
        else if (result[nmax] != 0)
        {
            for (int i = nmax; i >=0; i--)
                printf("%d", result[i]);
        }
    }
    return 0;
}