//与 13. Roman to Integer 用的是同一张表
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
    string intToRoman(int num) {
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

        string res = "";
        for (int i = roman_map.size() - 1; i >= 0;)
        {
            int cur_roman_value = roman_map[i].value;
            if (num < cur_roman_value)
            {
                i--;
            }
            else
            {
                int divide_res = num / cur_roman_value;
                //超出当前字符允许出现的次数上限，说明应该找 sub_roman
                if (!roman_map[i].is_sub && divide_res >= roman_map[i].limited)
                {
                    for (size_t j = 0; j < roman_map.size(); j++)
                    {
                        if (j + 2 < roman_map.size() &&
                            num >= roman_map[j].value &&
                            num < roman_map[j + 2].value
                            )
                        {
                            res += roman_map[j].roman_str;
                            //sub_roman_map 的数字都是只允许出现一次的，就不用 * divide_res 了
                            num -= roman_map[j].value;
                            break;
                        }
                    }
                }
                else
                {
                    for (size_t j = 0; j < divide_res; j++)
                    {
                        res += roman_map[i].roman_str;
                    }
                    num -= cur_roman_value * divide_res;
                }
            }
        }
        return res;
    }
};
