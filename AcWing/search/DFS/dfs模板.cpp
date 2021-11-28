void dfs(int x) {
    v[x] = 1; //记录点x被访问过， v是 visit的缩写
    for (int i = head[x]; i; i = next[i]) {
        int y = ver[i];
        if (v[y]) continue; //点 y 已经被访问过了
        dfs(y);
    }
}