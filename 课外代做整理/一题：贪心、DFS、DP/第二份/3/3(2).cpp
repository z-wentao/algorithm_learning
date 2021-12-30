#include <vector>
#include <iostream>
using namespace std;

int main()
{
	float k = 0;
	cin >> k;
	if (k - (int)k != 0) {
		cout << "不能恰好支付" << endl;
		return 0;
	}
	// 将二维dp数组压维 
	vector<int> dp(k + 1, k);
	// 记录所有面值 
	int a[] = { 1,2,5,10,20,50,100 };
	dp[0] = 0;
	// 从小到大枚举所有面值 
	for (int i = 0; i < 7; i++)
	{
		// 维护当前金额可以由哪些状态转移过来 
		for (int j = a[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - a[i]] + 1);
		}
	}
	// 输出总金额为k 的结果 
	cout << dp[k] << endl;
	return 0;
}
