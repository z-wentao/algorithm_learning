#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, k;
int q[N];

int quick_select(int l, int r, int k) { // 快速选择函数 
    if (l >= r) {	// 如果左端点与右端点重合，返回左端点的值 
        return q[l];
    }
    int x = q[l + r >> 1]; // x == (l+r)/2 记为左端点与右端点的中间值 
    int i = l - 1, j = r + 1; //  i, j 定义为新的区间 
    while (i < j) { // 当区间左端点小于右端点时 
        do i++; while (q[i] < x); // 区间左端点向右逼近 
        do j--; while (q[j] > x); // 区间右端点向左逼近 
        if (i < j) {
            swap(q[i], q[j]);  
        }
    }
    // l - j 有 j-l+1个数字
    int sl = j - l + 1;
    if (k <= sl) { // 判断应从左半段还是右半段进行下一次查找 
        quick_select(l, j, k);
    } else {
        quick_select(j + 1, r, k - sl);
    }
}

int main() {
    // 读入变量 
    cin >> n >> k;
    for (int i = 0; i < n; i++) { //读入数组 
        cin >> q[i];
    }

    cout << quick_select(0, n - 1, k) << endl; // 调用快速选择函数并返回结果 
    return 0;
}
