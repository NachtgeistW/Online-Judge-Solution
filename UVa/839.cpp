#include<iostream>
using namespace std;
bool solve(int& w)
{
	int wl, dl, wr, dr;
	cin >> wl >> dl >> wr >> dr;
	bool left = true, right = true;
	if(wl == 0) left = solve(wl);
	if(wr == 0) right = solve(wr);
	w = wl + wr;
	return left && right && (wl * dl == wr * dr);
}

int main(void)
{
	int n, w = 0;
	cin >> n;
	while(n--)
	{
		if(solve(w)) cout << "YES\n";
		else cout << "NO\n";
		if(n) cout << '\n';
}
	return 0;
}
