/*
    通过多次深度优先遍历， 可以划分出一张无向图的各个连通块。
同理，对一个森林进行深度优先遍历，可以划分出森林中的每棵树，
如下代码：cnt就是无向图中连通块的个数，v 数组标记了每个点属于
哪个连通块。
*/
void dfs(int x) {
    v[x] = cnt; 
    for (int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if (v[y]) continue;
        dfs(y);
    }
}
for (int i = 1; i <= n; i++)    // 在 int main() 中 
    if (!v[i]) {
        cnt++;
        dfs(i);
    }