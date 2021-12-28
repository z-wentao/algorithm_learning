#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T -- )
	{
		int x;
		cin >> x;
		deque<int> d;
		while (x -- )
		{
			int a;
			cin >> a;
			if (d.size() == 0) d.push_back(a);
			else if (d.front() < a) d.push_back(a);
			else d.push_front(a);
		}
		while (d.size())
		{
			int t = d.front();
			d.pop_front();
			cout << t << ' ';
		}
		cout << endl;
	}
	return 0;
}
