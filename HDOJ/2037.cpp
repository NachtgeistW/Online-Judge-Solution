//http://acm.hdu.edu.cn/showproblem.php?pid=1049
#include<iostream>
using namespace std;

struct program
{
	int begin;
	int end;
};

int cmp(const void* a, const void* b) {
	const struct program* p = (program*)a;
	const struct program* q = (program*)b;
	return p->end - q->end;
}
int main()
{
	ios::sync_with_stdio(false);
	program p[100], res[100];
	int n, begin, end;
	while (cin >> n && n != 0)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> begin >> end;
			p[i].begin = begin;
			p[i].end = end;
		}
		qsort(p, n, sizeof(p[0]), cmp);
		int k = 0;
		res[k] = p[0];
		for (int i = 1; i < n; i++)
		{
			if(p[i].begin >= res[k].end)
			{
				k++;
				res[k] = p[i];
			}
		}
		cout << k + 1 << '\n';
	}
	return 0;
}
