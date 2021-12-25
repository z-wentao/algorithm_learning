/*用搜索朴素遍历状态空间*/
int n, a[105];
int k[105], ans;
void dfs(int len) {
    if (len > ans) {
        ans = len;
        // 如果需要记录方案， 记录 {A[k[1]], A[k[2]], ..., A[k[len]]}
    }
    // {k[1], k[2], ..., k[len]}
    // B = {A[k[1], A[k[2]], ..., A[k[len]]}
    for (int i = k[len] + 1; i <= n; i++)
        if (a[i] > a[k[len]]) {
            k[len + 1] = i;
            dfs(len + 1);
        }
}
k[0] = 0, a[0] = -{1<<30};
dfs(0);

虽然维护了一个长度为len的序列(len的个数)
但是其实我们推导时只用到了k[len]这个结尾

void dfs(int len, int tail) {
    if (len > ans) {
        ans = len;
    }
    for (int i = tail + 1; i <= n; i++) 
        if (a[i] > a[tail])
            dfs(len + 1, i);
}
a[0] = -(1<<30);
dfs(0, 0);

子结构
（以8为结尾的上升子序列） 代表元素    最优解
{1, 2, 8}                 8       {1, 2, 8} len = 3
{3, 8}
{1, 8}
{2, 8}
{8}

更大的子结构
（以9为结尾的上升子序列）

当子结构之间都可以用代表元素和最优解来推导时
称问题满足最优子结构性质

新状态： 结尾下表
状态总数： n
f[i]表示以a[i]为结尾的最长上升子序列的长度

//  第一种写法： 考虑f[i]可以推导到哪些状态
f[0] = 0;
for (int i = 0; i < n; i++) // i: 结尾下标
    for (int j = i + 1; j <= n; j++) // j: 下一个数
        if (a[j] > a[i]) f[j] = max(f[j], f[i] + 1);

// 第二种写法： 考虑f[i]可以由哪些状态得到
f[0] = 0;
for (int i = 1; i <= n; i++)
    for (int j = 0; j < i; j++) // 前一个数
        if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);