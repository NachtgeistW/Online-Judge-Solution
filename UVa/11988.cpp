//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=229&page=show_problem&problem=3139
#include <iostream>
#include <list>
#include <string>
using namespace std;
int main(void)
{
	list<char> alist;
	string str;
	while (getline(cin, str))
	{
		list<char>::iterator it = alist.begin();
		for (string::iterator i = str.begin(); i != str.end(); i++)
		{
			if (*i == '[')
				it = alist.begin();
			else if (*i == ']')
				it = alist.end();
			else
				alist.insert(it, *i);
		}
		for (list<char>::iterator i = alist.begin(); i != alist.end(); i++)
			cout << *i;
		putchar('\n');
		alist.clear();
	}
	return 0;
}
