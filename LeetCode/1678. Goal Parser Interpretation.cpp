class Solution {
public:
    string interpret(string command)
    {
        
        string res;
        for (auto it = command.begin(); it != command.end(); it++)
        {
            if (*it == 'G')
                res += 'G';
            else
            {
                auto it2 = it;
                if (*(++it2) == ')')
                {
                    res += 'o';
                    it++;
                }
                else
                {
                    res += "al";
                    it++;
                    it++;
                    it++;
                }
            }
        }
        return res;
    }
};
