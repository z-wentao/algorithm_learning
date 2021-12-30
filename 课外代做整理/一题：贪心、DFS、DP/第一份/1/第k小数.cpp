#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll; 

int patition(int a[], int left, int right){ //对 left ~  right 进行划分 
	int x = a[left];  
	while(left < right){ // 二分查找的条件 
		while(left<right && a[right]>=x) right--; // 当区间仍存在且a[right]>=x, 右端向左逼近 
		a[left] = a[right];	//赋值 
		while(left<right && a[left]<=x) left++; // 当区间仍存在且a[left]<=x, 左端向右逼近 
		a[right] = a[left];	//赋值 
	}
	a[left] = x; // 将x赋值给左端点 
	return left; // 返回左端点的下标 
}

void find(int a[], int left, int right, int k){	//在 left ~  right 寻找 
	int pos = patition(a, left, right);	// 在区间left~right进行寻找，并返回查找位置 
	if(pos == k) printf("%d\n", a[pos]);  // 如果查到了位置，输出该位置的元素 
	else if(pos > k) find(a, left, pos-1, k);	// 如果查询的位置大于k，在左边接着查找 
	else find(a, pos+1, right, k);	// 如果查询的位置小于k， 在右边接着查找 
}

int main(){
	int n, k, a[100005]; // 定义长度，位数，和数组 
	cout << "输入数组长度和要查找的数的位数:" << endl; // 输出提示信息 
	scanf("%d%d", &n, &k);	// 输入数组长度和位数 
	cout << "输入数组每个元素" << endl;	// 输出提示信息 
	for(int i=1; i<=n; i++) scanf("%d", a+i);	// 输入数组元素 
	find(a, 1, n, k);
}
