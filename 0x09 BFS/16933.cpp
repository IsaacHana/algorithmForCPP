#include <bits/stdc++.h>
using namespace std;

const int MX = 987654321;
int dist[2][11][1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    string board[N];
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    queue<tuple<int, int, int, int>> Q;
    Q.push({1, K, 0, 0});
    dist[1][K][0][0] = 1;

    while (!Q.empty()) {
        int light, k, x, y;
        tie(light, k, x, y) = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (board[nx][ny] == '1') {
                if (k <= 0) continue;
                if (light) {
                    if (dist[!light][k - 1][nx][ny]) continue;
                    dist[!light][k - 1][nx][ny] = dist[light][k][x][y] + 1;
                    Q.push({!light, k - 1, nx, ny});
                } else {
                    if (dist[!light][k][x][y]) continue;
                    dist[!light][k][x][y] = dist[light][k][x][y] + 1;
                    Q.push({!light, k, x, y});
                }
            } else {
                if (dist[!light][k][nx][ny]) continue;
                dist[!light][k][nx][ny] = dist[light][k][x][y] + 1;
                Q.push({!light, k, nx, ny});
            }
        }
    }

    int ans = MX;

    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= K; j++) {
            if (dist[i][j][N - 1][M - 1]) ans = min(ans, dist[i][j][N - 1][M - 1]);
        }
    }

    if (ans == MX)
        cout << -1;
    else
        cout << ans;
}