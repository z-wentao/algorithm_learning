void bfs() {
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(1); d[1] = 1;
    while (q.size() > 0) {
        int x = q.front(); q.pop();
        for (int i = head[x]; i; i = next[i]) {
            int y = ver[i];
            if (d[y]) continue;
            d[y] = d[y] + 1;
            q.push(y);
        }
    }
}