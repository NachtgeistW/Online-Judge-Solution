#include <cmath>
#include <algorithm>
#include <iostream>

#define MAXN 100005
using namespace std;
struct point
{
	double x, y;
};
//point_y是用来存放符合条件的点的x坐标的
struct point p[MAXN], * point_x[MAXN], * point_y[MAXN];

double get_dis(point* p1, point* p2)
{
	return sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}

bool compare_x(point* p1, point* p2) { return p1->x < p2->x; }
bool compare_y(point* p1, point* p2) { return p1->y < p2->y; }

//核心代码
double closest(const int left, const int right)
{
	//如果是相邻的两个点
	if (left + 1 == right)
		return get_dis(point_x[left], point_x[right]);

	//如果是相隔一个点的两个点
	if (left + 2 == right)
		return min(get_dis(point_x[left], point_x[left + 1]),
			min(get_dis(point_x[left + 1], point_x[right]),
				get_dis(point_x[left], point_x[right])));

	//相隔多于两个点的通常情况
	const int mid = (left + right) / 2;
	double res = min(closest(left, mid), closest(mid + 1, right));//折半递归求解
	int i, count = 0;
	//把x坐标在point_x[mid].x-ans~point_x[mid].x+ans范围内的点取出来
	for (i = left; i <= right; i++)
	{
		//如果x在[mid-ans, mid+ans]内
		if (point_x[i]->x >= point_x[mid]->x - res && point_x[i]->x <= point_x[mid]->x + res)
			//将符合条件的点放到point_y里
			point_y[count++] = point_x[i];
	}
	sort(point_y, point_y + count, compare_y);//按y坐标排序
	//遍历point_y数组找最小的y坐标差
	for (i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)//point_y数组中的点是按照y坐标升序的
		{
			//如果光是y坐标的距离就已经比res大了，那就直接跳过去找下一个
			if (point_y[j]->y - point_y[i]->y >= res)
				break;
			res = min(res, get_dis(point_y[i], point_y[j]));
		}
	}
	return res;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
			point_x[i] = &p[i];
		}
		//先按x坐标的大小排好序
		sort(point_x, point_x + n, compare_x);
		const double distance = closest(0, n - 1);
		printf("%.2lf\n", distance / 2);
	}
	return 0;
}
