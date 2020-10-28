class Solution {
public:
    int deduplication(string& status)
    {
        int count = 0;
        for (size_t i = 0; i < status.size(); i++)
        {
            size_t j = i + 1;
            if (status[i] != status[j])
            {
                count++;
            }
        }
        return count;
    }

    int minFlips(string target)
    {
        return target[0] == '0' ? deduplication(target) - 1 : deduplication(target);
    }

};
