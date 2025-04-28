#include <iostream>
#include <algorithm>
#include <cstring>
#define x first
#define y second
using namespace std;

const int N = 1010, M = N * N;

typedef pair<int, int> PII;

int n, m;
char g[N][N];
bool st[N][N];
PII q[M];

void bfs(int sx, int sy)
{
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = 1;
    
    while (hh <= tt)
    {
        PII t = q[hh ++ ];
        
        for (int i = t.x - 1; i <= t.x + 1; i ++ )
            for (int j = t.y - 1; j <= t.y + 1; j ++ )
            {
                if (i == t.x && j == t.y) continue;
                if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] == '.' || st[i][j])
                    continue;
                q[ ++ tt ] = {i, j};
                st[i][j] = 1;
            }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) 
        scanf("%s", g[i]);
        int cnt = 0;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            if (g[i][j] == 'W' && !st[i][j])
            {
                cnt ++ ;
                bfs(i, j);
            }

    cout << cnt << endl;
}
