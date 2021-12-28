#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int k = 0;
	cin >> k;
	vector<vector<int>> dp(7, vector<int>(k + 1, k));
	int a[] = { 1,2,5,10,20,50,100 };
	for (int i = 0; i <= k; i++) dp[0][i] = i;
	for (int i = 1; i < 7; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j < a[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = min(dp[i][j - a[i]] + 1, dp[i - 1][j]);
		}
	}
	cout << dp[6][k] << endl;
	return 0;
}
