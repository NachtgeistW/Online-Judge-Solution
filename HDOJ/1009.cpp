//http://acm.hdu.edu.cn/showproblem.php?pid=1005
//贪心
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
struct str
{
    //J is JavaBean the FatMouse gets, F is the cat food it pays
    double J;
    double F;
    double a;
};

bool cmp(const str &str1, const str &str2)
{
    return str1.a > str2.a;
}

int main(void)
{
    //M is the pounds of cat food, N is the number of warehouse
    int M, N; 
    while (cin >> M >> N && M != -1 && N != -1)
    {
        str data[1010];
        double res = 0;
        if (M == 0)
        {
            for (int i = 0; i < N; i++)
            {
				cin >> data[i].J >> data[i].F;
                if (data[i].F == 0)
                    res += data[i].J;
            }
        }
        else
        {
            for (int i = 0; i < N; i++)
            {
				cin >> data[i].J >> data[i].F;
                data[i].a = data[i].J / data[i].F;
            }
            //注意这里
            sort(data, data + N, cmp);
            for (int i = 0; i < N; i++)
            {
                if (M > data[i].F)
                {
                    res += data[i].J;
                    M -= data[i].F;
                }
                else
                {
                    res += data[i].a * (double)M;
                    break;
                }
            }
        }
        //输出格式一定得是小数点后三位
        printf("%.3lf\n", res);
    }
    return 0;
}