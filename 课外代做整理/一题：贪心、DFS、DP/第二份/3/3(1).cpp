#include <iostream>
using namespace std;
int a[7] = { 1,2,5,10,20,50,100 }; // 面值 
int num[7], sol[7], ans = 0x3fffffff; // num[]记录中间 
void dfs(int st,int k,int cnt)
{
	// 退出条件： 搜索到最小面额 
	if (st == 0)
	{
		// 最小面额张数等于剩余的k值 
		num[0] = k;
		// 总张数加上剩余k值 
		cnt += k;
		// 维护最小张数，并将当前方案存入数组sol[]. 
		if (cnt < ans)
		{
			ans = cnt;
			for (int i = 0; i < 7; i++) sol[i] = num[i];
		}
		return;
	}
	// 从大面值开始递归搜索	
	for (int i = 0; i * a[st] <= k; i++)
	{
		// num[]存储当前面值可以用几张 
		num[st] = i;
		// 面额减小, 剩余金额减少, 当前所用张数增加i 
		dfs(st - 1, k - i * a[st], cnt + i);
	}
}
int main()
{
	float k;
	scanf("%lf", &k);
	if (k - (int)k != 0) {
		cout << "不能恰好支付" << endl;
		return 0;
	}
	dfs(6, k, 0);

	printf("需要使用%4d张纸币\n", ans);
	for (int i = 0; i < 7; i++)
		printf("使用面值%4d元纸币%4d张\n", a[i], sol[i]);
	
	return 0;
}
