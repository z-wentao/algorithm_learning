#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <iomanip>
using namespace std;
typedef pair<int, int> PII;
const int N = 110, INF = 0x3f3f3f3f;
int a[N], n, m;
int d[N];
bool v[N];
int head[N], ver[N], nxt[N], tot, cnt, deg[N], b[N];
int t;
int g[N][N];
int dist[N];
bool st[N];
int p[N];
int h[N], w[N], e[N], ne[N], idx;
struct Edge{
    int a, b, w;
    
    bool operator< (const Edge &W) const
    {
        return w < W.w;
    }
}edges[1010];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges, edges + m);
    
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a = edges[i].a, b = edges[i].b,  w = edges[i].w;
        
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }
    
    if (cnt < n - 1) return INF;
    return res;
}


void add(int x, int y) {
	ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
}

void add_topsort(int x, int y) {
	ver[++tot] = y, nxt[tot] = head[x], head[x] = tot;
	deg[y]++;
}


void add_di(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int x) {
	a[++t] = x;
	v[x] = 1;
	for (int i = head[x]; i; i = nxt[i]) {
		int y = ver[i];
		if (v[y]) continue;
		dfs(y);
	}
	a[++t] = x;
}

void bfs() {
	memset(d, 0, sizeof(d));
	queue<int> q;
	q.push(1); d[1] = 1;
	while(q.size() > 0) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int y = ver[i];
			if (d[y]) continue;
			d[y] = d[x] + 1;
			q.push(y);
		}
	}
}
void topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (deg[i] == 0) q.push(i);
    while (q.size()) {
        int x = q.front(); q.pop();
        b[++cnt] = x;
        for (int i = head[x]; i; i = nxt[i]) {
            int y = ver[i];
            if (--deg[y] == 0) q.push(y);
        }
    }
}

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1; 
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size())
    {
        int x = heap.top().second;
        heap.pop();

        if (v[x]) continue;
        v[x] = true;

        for (int i = h[x]; i != -1; i = ne[i])
        {
            int y = e[i];
            if (d[y] > d[x] + w[i])
            {
                d[y] = d[x] + w[i];
                heap.push({d[y], y});
            }
        }
    }

    if (d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}


/*
数据:
9
8
1 2
1 7
1 4
2 8
2 5
4 3
4 6
3 9 
*/ 

void menu_show() {
	cout << "-------------------menu-----------------" << endl;
	cout << "输入1建立邻接表, 并生成其dfs序和bfs层次" << endl;
	cout << "输入2建立邻接表, 并生成其拓扑序" << endl;
	cout << "输入3建立邻接矩阵结构的图, 并用prim生成其最小生成树" << endl;
	cout << "输入4建立邻接矩阵结构的图, 并用kruskal生成其最小生成树" << endl;
	cout << "输入5建立邻接表, 并用单源最短路算法堆优化dijkstra求最短路" << endl;
	cout << "输入6退出" << endl; 
	cout << "-------------------menu-----------------" << endl;
}

void menu(int flag) {
	if (flag == 1) {
			cout << "请输入点数: " << endl;
		cin >> n; 
		cout << "请输入边数: " << endl; 
		cin >> m;
		for (int i = 0; i < m; i++) {
			cout << "请插入边: " << endl;
			int x, y; cin >> x >> y;
			add(x, y), add(y, x);
		}
		cout << "图的dfs序是：" << endl;
		dfs(1); 
		for (int i = 1; i <= t; i++) cout << a[i] << ' ';
		bfs(); 
		cout << endl << "图中每个点bfs的层数为: " << endl; 
		for (int i = 1; i <= n; i++) cout << d[i] << ' ';
	}
	
	else if (flag == 2) {
		cout << "请输入点数和边数" << endl; 
		cin >> n >> m;
	    for (int i = 1; i <= m; i++) {
	        int x, y;
	        cout << "请输入边的起点和终点： "; 
	        scanf("%d%d", &x, &y);
	        add_topsort(x, y);
	    }
		topsort();
		cout << endl << "图的拓扑序为: " << endl; 
		if (cnt < t) puts("-1");
	    else for (int i = 1; i <= cnt; i++) printf("%d ", b[i]);
	}
	
	else if (flag == 3) {
		cout << "请输入点数和边数" << endl; 
		scanf("%d%d", &n, &m);
	    memset(g, 0x3f, sizeof g);	
	    while (m -- )
	    {
	        int a, b, c;
	        cout << "请输入每条边的起点、终点和权值: "; 
	        scanf("%d%d%d", &a, &b, &c);
	        g[a][b] = g[b][a] = min(g[a][b], c);
	    }
	    int p = prim();
	    if (p == 0x3f3f3f3f) puts("impossible");
	    else {
	    	printf("最小生成树的大小是%4d\n", p);
		}
	}
	
	if (flag == 4) {
		cout << "请输入点数和边数" << endl; 
		scanf("%d%d", &n, &m);
	    
	    for (int i = 0; i < m; i ++ )
	    {
	        int a, b, w;
	        cout << "请输入每条边的起点、终点和权值: "; 
	        scanf("%d%d%d", &a, &b, &w);
	        edges[i] = {a, b, w};
	    }
	    
	    int t = kruskal();
	    
	    if (t == INF) puts("impossible");
	    else printf("%d\n", t);
	} 
	
	if (flag == 5) {
		cout << "请输入点数和边数" << endl; 
		scanf("%d%d", &n, &m);

	    memset(h, -1, sizeof h);
	    while (m -- )
	    {
	        int a, b, c;
	        cout << "请输入每条边的起点、终点和权值: "; 
	        scanf("%d%d%d", &a, &b, &c);
	        add_di(a, b, c);
	    }
	    dijkstra();
	    
	    for (int i = 1; i <= n; i++)
	    	cout << "1号点到" << setw(4) << i << "号点的距离是" << setw(4) << d[i] << endl;
	} 
	else if (flag == 6) return;
	
} 

int main() {
	menu_show();
	int flag = -1;
	cin >> flag; 
	menu(flag);
	
	return 0;
} 
