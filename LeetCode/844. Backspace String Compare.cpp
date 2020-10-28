class Solution {
public:
bool backspaceCompare(string S, string T) {
    stack<char> s, t;
    for (auto it : S)
    {
        if (it == '#')
        {
            if (s.empty())
                continue;
            s.pop();
        }
        else
            s.push(it);
    }
    for (auto it : T)
    {
        if (it == '#')
        {
            if (t.empty())
                continue;
            t.pop();
        }
        else
            t.push(it);
    }

    if (s.empty() && t.empty())     return true;
    if (s.size() != t.size())   return false;

    while(!s.empty())
    {
        if (s.top() != t.top())
            return false;
        s.pop();
        t.pop();
    }
    return true;
}
};
