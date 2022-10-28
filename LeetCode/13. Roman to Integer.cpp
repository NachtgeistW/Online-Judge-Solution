class Roman 
{
public:
    string roman_str;
    int value;
    unsigned int step_forward;
    unsigned int limited;
    bool is_sub;
    Roman(string roman_str, int num, unsigned int step_forward, unsigned int limited, bool is_sub) :
        roman_str(roman_str), value(num), step_forward(step_forward), limited(limited), is_sub(is_sub) {}
};


class Solution {
public:
    int romanToInt(string s) {
        vector<Roman> roman_map =
        {
            { "I", 1, 1, 4, false},
            { "IV", 4, 2, 2, true},
            { "V", 5, 1, 2, false},
            { "IX", 9, 2, 2, true},
            { "X", 10, 1, 4, false},
            { "XL", 40, 2, 2, true},
            { "L", 50, 1, 2, false},
            { "XC", 90, 2, 2, true},
            { "C", 100, 1, 4, false},
            { "CD", 400, 2, 2, true},
            { "D", 500, 1, 2, false},
            { "CM", 900, 2, 2, true},
            { "M", 1000, 1, 4, false},
        };

        int res = 0;
        for (int i = s.size() - 1; i >= 0;)
        {
            int j = 0;
            //确定 j 的值，给后面用
            for (; j < roman_map.size(); j++)
            {
                if (!roman_map[j].is_sub && s[i] == roman_map[j].roman_str[0])
                {
                    break;
                }
            }
            
            bool is_sub_roman_str = false;
            //确认有没有合法的 sub_roman
            //k 是从 IV 开始跳着找的
            for (int k = 1; k < roman_map.size(); k += 2)
            {
                if (i - 1 >= 0 && 
                    s[i] == roman_map[k].roman_str[1] &&
                    s[i - 1] == roman_map[k].roman_str[0])
                {
                    res += roman_map[k].value;
                    i -= roman_map[k].step_forward;
                    is_sub_roman_str = true;
                    break;
                }
            }
            //没有合法的 sub_roman，直接普通地加上当前字母的值就可以了
            if (!is_sub_roman_str)
            {
                res += roman_map[j].value;
                i -= roman_map[j].step_forward;
            }
        }
        return res;
    }
};
