#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
    char a, b, c;
    while (cin >> a >> b >> c)
    {
        sort(a, b, c);
        cout << a << b << c << '\n';
    }
}