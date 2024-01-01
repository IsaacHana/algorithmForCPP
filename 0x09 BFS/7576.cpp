#include <bits/stdc++.h>
using namespace std;

int storage[1002][1002];
int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;

    queue<pair<int, int>> Q;
    int M, N;
    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int val;
            cin >> val;

            storage[i][j] = val;
            if (val == 1) {
                Q.push({i, j});
            } else if (val == 0) {
                dist[i][j] = -1;
            }
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
            if (dist[nx][ny] >= 0) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (dist[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans;
}