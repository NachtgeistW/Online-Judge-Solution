class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        for (auto var : nums)
        {
            res.push_back(var * var);
        }
        std::sort(res.begin(), res.end());
        return res;

    }
};
