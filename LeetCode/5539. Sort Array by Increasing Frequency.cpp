class Solution
{
public:
    vector<int> frequencySort(vector<int>& nums)
    {
        //得到数字出现次数
        map<int, int> m;
        for (auto i : nums)
            m[i]++;

        //按出现次数和数字大小升序排序
        map<int, vector<int>> m2;
        for (auto i : m)
            m2[i.second].emplace_back(i.first);

        //逆序将数字插入vector中
        vector<int> res;
        for (auto i : m2)
        {
            for (auto it = i.second.rbegin(); it != i.second.rend(); ++it)
                res.insert(res.end(), i.first, *it);
        }
        return res;
    }
};
