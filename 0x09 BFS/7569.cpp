#include <bits/stdc++.h>
using namespace std;

int dist[101][101][101];
queue<tuple<int, int, int>> Q;
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, H;

    cin >> M >> N >> H;

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int val;
                cin >> val;
                if (val == 1) {
                    Q.push({k, i, j});
                }
                if (val == 0) {
                    dist[k][i][j] = -1;
                }
            }
        }
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        int curX, curY, curZ;
        tie(curZ, curX, curY) = cur;
        for (int dir = 0; dir < 6; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
            if (dist[nz][nx][ny] >= 0) continue;
            dist[nz][nx][ny] = dist[curZ][curX][curY] + 1;
            Q.push({nz, nx, ny});
        }
    }

    int ans = 0;

    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // cout << dist[k][i][j] << " ";
                if (dist[k][i][j] == -1) {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, dist[k][i][j]);
            }
            // cout << '\n';
        }
        // cout << '\n';
    }

    cout << ans;
}