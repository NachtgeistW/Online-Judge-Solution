class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res;
        res.resize(s.size());
        for (size_t i = 0; i < s.size(); i++)
        {
            res[indices[i]] = s[i];
        }
        return res;
    }
};
