#include <iostream>
#include <iomanip>
using namespace std;
// 定义a数组存储面值 
int a[7] = { 1,2,5,10,20,50,100 };
// 定义num[] 存储过程中的张数， sol[] 存储最优解， ans存储最终总张数 
int num[7], sol[7], ans = 0x3fffffff;
// dfs函数， st表示当前枚举到哪个面额， k表示剩余的金额， cnt表当前的总张数 
bool A(float a)
{   
    if(a-(int)a==0) //核心在此a-(int)a
    return 0;
    else return 1;
}
void dfs(int st,int k,int cnt)
{
	// dfs 退出条件：枚举到面额为1时 
	if (st == 0)
	{
		// 剩余的金额即为 面值为1的金额所需的 张数 
		num[0] = k;
		// 总张数加上当前的剩余金额 
		cnt += k;
		// 维护最优解 
		if (cnt < ans)
		{
			ans = cnt;
			// 将答案存入最优解数组中 
			for (int i = 0; i < 7; i++) sol[i] = num[i];
		}
		// 退出这个程序 
		return;
	}
	// 枚举所有状态空间 
	for (int i = 0; i * a[st] <= k; i++)
	{
		// 当前面值的张数等于 i 
		num[st] = i;
		// 对当前方案进行深搜 
		dfs(st - 1, k - i * a[st], cnt + i);
	}
}
int main()
{
	// 定义初始金额 并赋值 
	float k;
	cin >> k;
	if(A(k)) {
		cout << "不能恰好支付" << endl;
		return 0;
	}
	//  搜索开始 
	dfs(6, k, 0);

	// 输出总金额 
	cout << "最小需要" << setw(4) << ans << "张纸币" << endl;
	for (int i = 0; i < 7; i++) // 输出最优解 
	{
		cout << "使用面值" << setw(4) << a[i] << "元纸币" << setw(4) << sol[i] << "张" << endl;
	}
	return 0;
}
