#include <iostream>
#include <iomanip> 
using namespace std;

int main()
{
	int k = 0; // 定义总金额k 
	cin >> k; // 输入k的值 

	int c100 = k / 100; k %= 100; // 计算100面额应用的张数 
	int c50 = k / 50; k %= 50; // 计算50面额应用的张数 
	int c20 = k / 20; k %= 20;// 计算20面额应用的张数 
	int c10 = k / 10; k %= 10;// 计算10面额应用的张数 
	int c5 = k / 5; k %= 5;// 计算5面额应用的张数 
	int c2 = k / 2; k %= 2;// 计算2面额应用的张数 
	int c1 = k;	// 最后剩下的就是1元的张数 

	int ans = c100 + c50 + c20 + c10 + c5 + c2 + c1; // 计算总共需要的张数 
	// 输出结果 
	cout << "最小需要" << setw(4) << ans << "张纸币" << endl;
	cout << "使用面值" << setw(4) << 100 << "元纸币" << setw(4) << c100 << "张" << endl;
	cout << "使用面值" << setw(4) << 50 << "元纸币" << setw(4) << c50 << "张" << endl;
	cout << "使用面值" << setw(4) << 20 << "元纸币" << setw(4) << c20 << "张" << endl;
	cout << "使用面值" << setw(4) << 10 << "元纸币" << setw(4) << c10 << "张" << endl;
	cout << "使用面值" << setw(4) << 5 << "元纸币" << setw(4) << c5 << "张" << endl;
	cout << "使用面值" << setw(4) << 2 << "元纸币" << setw(4) << c2 << "张" << endl;
	cout << "使用面值" << setw(4) << 1 << "元纸币" << setw(4) << c1 << "张" << endl;

	return 0;
}
