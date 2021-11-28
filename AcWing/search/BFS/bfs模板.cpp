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
/*
    广度优先遍历的同时顺便求出了一个 d[] 数组。 对于一棵树来讲，
d[x] 就是点 x 在树中的深度。 对于一张图来讲， d[x] 被称为点 x
的层次。
*/