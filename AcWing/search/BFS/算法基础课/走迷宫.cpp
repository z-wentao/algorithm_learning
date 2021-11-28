#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;
int g[N][N], d[N][N];
int n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void bfs() {
    queue<PII> q;
    q.push({1, 1}); d[1][1] = 0;
    while (q.size() > 0) {
        auto x = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int a = x.first + dx[i], b = x.second + dy[i];
                if (d[a][b] || g[a][b]) continue;
                d[a][b] = d[x.first][x.second] + 1;
                q.push({a, b});
        }
    }
}
int main() {
    cin >> n >> m;
    memset(g, 1, sizeof g);
    for (int i = 1; i <= n; i++)   
        for (int j = 1; j <= m; j++)    
        {
            int x; cin >> x;
            if (x == 0) g[i][j] = x;
            else continue;
        }
    bfs();
    cout << d[n][m] << endl;
    return 0;
}