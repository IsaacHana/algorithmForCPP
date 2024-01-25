#include <bits/stdc++.h>
using namespace std;

bool light[101][101];
bool vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    queue<pair<int, int>> adj[N + 1][N + 1];
    while (M--) {
        int x, y, sx, sy;
        cin >> x >> y >> sx >> sy;

        adj[x][y].push({sx, sy});
    }

    queue<pair<int, int>> Q;
    Q.push({1, 1});
    light[1][1] = true;
    vis[1][1] = true;

    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front();
        Q.pop();

        while (!adj[x][y].empty()) {
            auto cur = adj[x][y].front();
            adj[x][y].pop();
            if (vis[cur.first][cur.second]) continue;

            light[cur.first][cur.second] = true;

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if (vis[nx][ny]) {
                    vis[cur.first][cur.second] = true;
                    Q.push({cur.first, cur.second});
                    break;
                }
            }
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (!light[nx][ny]) continue;
            if (vis[nx][ny]) continue;

            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (light[i][j]) ans++;
        }
    }
    cout << ans;
}