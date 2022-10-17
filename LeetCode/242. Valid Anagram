class Solution {
public:
    bool isAnagram(string s, string t) {
        unsigned long long hash[26]{};
        for (auto var : s)
        {
            hash[var - 'a']++;
        }
        for (auto var : t)
        {
            hash[var - 'a']--;
        }
        for (auto var : hash)
        {
            if (var != 0)
            {
                return false;
            }
        }
        return true;
    }
};
