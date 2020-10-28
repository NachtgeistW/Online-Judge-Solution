class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> m1;
        set<int> count;
        for (auto it = arr.begin(); it != arr.end(); ++it)
        {
            m1[*it]++;
        }
        for (auto it = m1.begin(); it != m1.end(); ++it)
        {
            if (!count.insert((*it).second).second)
                return false;
        }
        return true;
    }
};
