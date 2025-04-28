void dfs(int x) {
    a[++m] = x; // a数组存储树的dfs序
    v[x] = 1;   // 记录点 x 被访问过
    for (int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if (v[y]) continue;
        dfs(y);
    }
    a[++m] = x;
}