/*
测试数据 
3 3
1 2 2
2 3 1
1 3 4
*/ 
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
	cout << "输入点数和边数" << endl; 
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);
    while (m -- )
    {
        int a, b, c;
        cout << "输入边的起点终点和权值：" << endl; 
        scanf("%d%d%d", &a, &b, &c);

        g[a][b] = min(g[a][b], c);
    }

	cout << "一号点到终点的距离是:" << endl; 
    printf("%d\n", dijkstra());

    return 0;
}
