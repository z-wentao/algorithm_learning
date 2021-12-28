#include <iostream>
using namespace std;

int main()
{
	int k = 0;
	cin >> k;	 

	int c100 = k / 100; k %= 100;
	int c50 = k / 50; k %= 50;
	int c20 = k / 20; k %= 20;
	int c10 = k / 10; k %= 10;
	int c5 = k / 5; k %= 5;
	int c2 = k / 2; k %= 2;
	int c1 = k;
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
