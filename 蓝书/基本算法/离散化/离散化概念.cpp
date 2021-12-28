离散化
    排序算法的第一个应用是离散化。
离散化:是把无穷大集合的若干个元素映射为有限集合以便于统计的方法。

void discrete() {
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) // can use STL unique
        if (i == 1 || a[i] != a[i - 1])
            b[++m] = a[i];
}

int query(int x) { // 查询 x 映射为哪个 1~m 之间的整数
    return lower_bound(b + 1, b + m + 1, x) - b;
}

关于lower_bound:
    在有序int数组(元素存放在下表1~n)中查找大于等于x的最小整数的下标:
    int i = lower_bound(a+1, a+n+1, x) - a;


// MY DESCRETE FUNCTION
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int b[110];
struct part{
    int p, v;
    inline friend bool operator< (part a, part b) {
        return a.p < b.p;
    }
}a[110];
void discrete() {
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i].v != a[i - 1].v) {
            b[++m] = a[i].v;
        }
    }
}

int query(int x) {
    return lower_bound(b+1, b+m+1, x) - b; 
}

int query2(int x) {
    return upper_bound(b+1, b + m + 1, x) - b;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].p >> a[i].v;
    discrete();
    for (int i = 1; i <= m; i++) cout << b[i] << ' ';
    cout << endl << query(15) << ' ' << query2(15) << endl;
}

// DATA FOR TEST
5
0 1
2 3
5 7
8 15
9 23
// ANWSER
1 3 7 15 23 
4 5