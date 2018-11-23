#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int cmp(int a, int b)
{
    return abs(a) > abs(b);
}

int main(void)
{
    vector<int> vec;
    int count, num;
    while (cin >> count && count != 0)
    {
        for(int i = 1; i <= count; i++)
        {
            cin >> num;
            vec.push_back(num);
        }
        sort(vec.begin(), vec.end(), cmp);
        for (auto i = vec.begin(); i != vec.end(); i++)
        {
            if (i != vec.begin())
                cout << ' ';
            cout << *i;
        }
        cout << endl;
        vec.clear();
    }
    return 0;
}
