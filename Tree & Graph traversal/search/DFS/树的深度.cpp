void dfs(int x) {
    v[x] = 1;
    for (int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if (v[y]) continue;
        d[y] = d[x] + 1; // 从父节点 x 到子节点 y 递推， 计算深度
        dfs(y);
    }
}