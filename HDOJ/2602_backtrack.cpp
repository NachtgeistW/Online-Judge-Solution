//http://acm.hdu.edu.cn/showproblem.php?pid=2602
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//T cases, the number of bones, the volume of his bag, best price, current price, current volume
int t = 0, n = 0, v = 0, best_p = 0, cur_p = 0, cur_v = 0;
struct bone
{
    int v;//体积
    int p;//价值
    double pv;//单位体积价值
};
bool sort_alg(const bone a, const bone b) { return a.pv > b.pv; }

//计算上界
int bound(vector<bone> vec, unsigned int i)
{
    int v_left = v - cur_v;//剩余容量
    int p = cur_p;//当前价值
    //按剩余价值从大到小的顺序把背包装满
    while (i <= vec.size() - 1 && vec[i].v <= v_left)
    {
        v_left -= vec[i].v;
        p += vec[i].p;
        i++;
    }
    //如果还有剩物品，则把不能全装进去的下一个物品“假装”装一部分进去，以此计算上界
    if (i <= vec.size() - 1)
        p += vec[i].p * v_left / vec[i].v;
    return p;
}

void backtrack(vector<bone> vec, const unsigned int i)
{
    if (i > vec.size() - 1)
    {
        best_p = cur_p;
        return;
    }
    //搜索左子树
    if (cur_v + vec[i].v <= v)
    {
        cur_p += vec[i].p;
        cur_v += vec[i].v;
        backtrack(vec, i + 1);//喜闻乐见的递归回溯搜索
        cur_p -= vec[i].p;
        cur_v -= vec[i].v;
    }
    //根据上界判断要不要搜索右子树
    if (bound(vec, i + 1) > best_p)
    {
        backtrack(vec, i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    int k = 1;
    while (k <= t)
    {
        //初始化
        cin >> n >> v;
        int temp_p, temp_v;
        vector<int>vec_v = { INT_MAX }, vec_p = { INT_MAX };
        vector<bone>vec;
        bone b;
        b.p = b.v = INT_MAX;
        b.pv = DBL_MAX;
        vec.push_back(b);
        //价值。注意下标是从 1 开始的
        for (int i = 1; i <= n; i++)
        {
            cin >> temp_p;
            vec_p.push_back(temp_p);
        }
        //体积
        for (int i = 1; i <= n; i++)
        {
            cin >> temp_v;
            vec_v.push_back(temp_v);
        }
        for (int i = 1; i <= n; i++)
        {
            if (vec_v[i] == 0) cur_p += vec_p[i];
            else
            {
                b.p = vec_p[i];
                b.v = vec_v[i];
                b.pv = (double)vec_p[i] / vec_v[i];
                vec.push_back(b);
            }
        }

        //求解
        std::sort(vec.begin(), vec.end(), sort_alg);
        if(v == 0) std::cout << cur_p;
        else {
            backtrack(vec, 1);
            std::cout << best_p;
        }
        if (k < n) std::cout << '\n';

        //归0
        best_p = 0, cur_p = 0, cur_v = 0;
        k++;
    }
}
