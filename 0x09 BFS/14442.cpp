#include <bits/stdc++.h>
using namespace std;

int MX = 987654321;
int board[1001][1001];
int dist[11][1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    queue<tuple<int, int, int>> Q;
    dist[K][0][0] = 1;
    Q.push({K, 0, 0});

    while (!Q.empty()) {
        int k, x, y;
        tie(k, x, y) = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny]) {
                if (k <= 0) continue;
                if (dist[k - 1][nx][ny]) continue;
                dist[k - 1][nx][ny] = dist[k][x][y] + 1;
                Q.push({k - 1, nx, ny});
            } else {
                if (dist[k][nx][ny]) continue;
                dist[k][nx][ny] = dist[k][x][y] + 1;
                Q.push({k, nx, ny});
            }
        }
    }

    int ans = MX;

    for (int i = 0; i <= K; i++) {
        // for (int j = 0; j < N; j++) {
        //     for (int k = 0; k < M; k++) {
        //         cout << dist[i][j][k];
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        if (dist[i][N - 1][M - 1]) {
            ans = min(ans, dist[i][N - 1][M - 1]);
        }
    }
    if (ans == MX)
        cout << -1;
    else
        cout << ans;
}