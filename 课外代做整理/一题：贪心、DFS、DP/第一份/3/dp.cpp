#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 定义初始状态 
	float k;
	cin >> k;
	if (k - (int)k != 0) {
		cout << "不能恰好支付" << endl;
		return 0;
	}
	// 定义dp数组， 并赋初值为k 
	vector<vector<int>> dp(7, vector<int>(k + 1, k));
	// a[] 记录所有面值 
	int a[] = { 1,2,5,10,20,50,100 };
	// 开始时，存储保底方案数 
	for (int i = 0; i <= k; i++) dp[0][i] = i;
	// 对后续面值进行枚举 
	for (int i = 1; i < 7; i++)
	{
		// 组成0~k的所有金额 
		for (int j = 0; j <= k; j++)
		{
			// 如果当前金额小于面额，就用更小的面额去凑 
			if (j < a[i]) dp[i][j] = dp[i - 1][j];
			// 其余情况就维护其最小值 
			else dp[i][j] = min(dp[i][j - a[i]] + 1, dp[i - 1][j]);
		}
	}
	// 输出最终状态 
	cout << dp[6][k] << endl;
	return 0;
}
