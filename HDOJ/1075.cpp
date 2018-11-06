//http://acm.hdu.edu.cn/showproblem.php?pid=1075
#include<iostream>
#include<string>
#include<map>
#include<sstream>
using namespace std;
int main(void)
{
	//读取字典是没有问题的
    ios_base::sync_with_stdio(false);
    string str;
    istringstream ist;
    map<string, string> dict;
    while(getline(cin, str))
    {
		if (str == "START")
			continue;
		else if (str == "END")
			break;
        else
        {
			ist.clear();
            ist.str(str);
            string str1, str2;
            ist >> str1 >> str2;
            auto check = dict.insert(make_pair(str2, str1));
        }
    }
    //接下来的文本转换有问题，以后再重写
    while(getline(cin, str))
    {
        if (str == "END")
            break;
        else if (str == "START")
            continue;
        else
        {
			ist.clear();
            ist.str(str);
            string str1;
            while (ist >> str1)
            {
				string str2;
				for (auto c = str1.begin(); c != str1.end(); c++)
				{
					if (isalpha(*c))
					{
						str2 += *c;
						auto it = dict.find(str2);
						if (it != dict.end())
						{
							str2 = it->second;
						}
					}
					else if (ispunct(*c))
					{
						auto it = dict.find(str2);
						if (it != dict.end())
							cout << it->second;
						else
							cout << str2;

						if (c == str1.cend())
							cout << *c << ' ';
						else
							cout << *c;
						str2.clear();
					}
				}
				cout << str2 << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
