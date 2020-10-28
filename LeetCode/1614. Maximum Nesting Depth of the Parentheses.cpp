class Solution {
public:
int maxDepth(string s)
{
    int i = 0, max = i;
    for (auto c : s)
    {
        if (c == '(')
        {
            i++;
            if (max < i)
                max = i;
        }
        if (c == ')')
        {
            i--;
        }
    }
    return max;
}
};
