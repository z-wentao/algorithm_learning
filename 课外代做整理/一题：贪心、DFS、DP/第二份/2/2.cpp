#include <iostream>
using namespace std;

int main()
{
	/* 定义变量， 赋初值 */ 
	int k = 0; 
	int c100, c50, c20, c10, c5, c2, c1;
	scanf("%d", &k);
	c100 = k / 100; k %= 100; // 计算100面额应用的张数 
	c50 = k / 50; k %= 50; // 计算50面额应用的张数 
	c20 = k / 20; k %= 20;// 计算20面额应用的张数 
	c10 = k / 10; k %= 10;// 计算10面额应用的张数 
	c5 = k / 5; k %= 5;// 计算5面额应用的张数 
	c2 = k / 2; k %= 2;// 计算2面额应用的张数 
	c1 = k;	// 最后剩下的就是1元的张数 
	int ans = c100 + c50 + c20 + c10 + c5 + c2 + c1;
	printf("最少需要%4d张纸币\n", ans);
	printf("最少需要 100元纸币%4d张\n", c100);
	printf("最少需要  50元纸币%4d张\n", c50);
	printf("最少需要  20元纸币%4d张\n", c20);
	printf("最少需要  10元纸币%4d张\n", c10);
	printf("最少需要   5元纸币%4d张\n", c5);
	printf("最少需要   2元纸币%4d张\n", c2);
	printf("最少需要   1元纸币%4d张\n", c1);
	
	return 0;
}
