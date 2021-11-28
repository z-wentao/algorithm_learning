/*
拓扑排序
    思想：不断选择入度为 0 的点 x，把 x 连向的点的入度 -1 。
可以结合 bfs 的框架来高效实现这个过程：
(1) 建立空的拓扑序列 A.  

(2) 预处理所有点的入度 deg[i], 起初把所有入度为 0 的点入队。  

(3) 取出队头节点 x , 把 x 加入拓扑序列 A 的末尾。  

(4) 对于从 x 出发的每条边 (x, y), 把 deg[y] -- 。若被减为 0， 则把 y 入队。  

(5) 重复第 3 ~ 4 步直到队列为空， 此时 A　即为所求。  

    拓扑排序可以判断有向图是否存在环。我们可以对任意有向图执行上述过程，在完成后检查A序列的长度。
    若 A 序列的长度小于图中点的数量， 则说明某些节点未被遍历，进而说明图中存在环。
*/
void add(int x, int y) {
    ver[++tot] = y, next[tot] = head[x], head[x] = tot;
    deg[y]++;
}
void topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) 
        if (def[i] == 0) q.push(i);
    while (q.size()) {
        int x = q.front(); q.pop();
        a[++cnt] = x;
        for (int i = head[x]; i; i = next[i]) {
            int y = ver[i];
            if (--deg[y] == 0) q.push(y);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }
    topsort();
    for (int i = 1; i <= cnt; i++) 
        printf("%d ", a[i]);
    cout << endl;
}