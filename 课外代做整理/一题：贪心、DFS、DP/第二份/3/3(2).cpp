#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int k = 0;
	cin >> k;
	vector<int> dp(k + 1, k);
	int a[] = { 1,2,5,10,20,50,100 };
	dp[0] = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = a[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		}
	}
	cout << dp[k] << endl;
	return 0;
}
