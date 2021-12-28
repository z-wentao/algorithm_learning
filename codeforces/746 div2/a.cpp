#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
int a[N];
int n, h;
int main()
{
	int T;
	cin >> T;
	while (T -- )
	{
		cin >> n >> h;
		for (int i = 0; i < n; i ++ ) 
		{
			int x;
			cin >> x;
			a[i] = x;
		}
		sort(a, a + n);
		reverse(a, a + n);
		int ans = 0;
		int t = 1;
		while (h > 0)
		{
			if (t == 1)
			{
				h -= a[0];
				ans ++ ;
				t = 2;
			}
			if (t == 2)
			{
				h -= a[1];
				ans ++ ;
				t = 1;
			}
		}	
		cout << ans << endl;
	}
	return 0;
}
