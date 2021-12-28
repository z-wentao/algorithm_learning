#include <iostream>
#include <iomanip>
using namespace std;
int a[7] = { 1,2,5,10,20,50,100 };
int num[7], sol[7], ans = 0x3fffffff;
void dfs(int st,int k,int cnt)
{
	if (st == 0)
	{
		num[0] = k;
		cnt += k;
		if (cnt < ans)
		{
			ans = cnt;
			for (int i = 0; i < 7; i++) sol[i] = num[i];
		}
		return;
	}
	for (int i = 0; i * a[st] <= k; i++)
	{
		num[st] = i;
		dfs(st - 1, k - i * a[st], cnt + i);
	}
}
int main()
{
	int k;
	cin >> k;
	dfs(6, k, 0);

	cout << "最小需要" << setw(4) << ans << "张纸币" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << "使用面值" << setw(4) << a[i] << "元纸币" << setw(4) << sol[i] << "张" << endl;
	}
	return 0;
}
