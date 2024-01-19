#include <bits/stdc++.h>
using namespace std;

const int MX = 987654321;
string board[1001];
int dist[2][1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    queue<tuple<int, int, int>> Q;
    Q.push({1, 0, 0});
    dist[1][0][0] = 1;

    while (!Q.empty()) {
        int wall_break, x, y;
        tie(wall_break, x, y) = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == '1') {  // ∫Æ ¿œ∂ß
                if (wall_break <= 0) continue;
                if (dist[wall_break - 1][nx][ny]) continue;

                dist[wall_break - 1][nx][ny] = dist[wall_break][x][y] + 1;
                Q.push({wall_break - 1, nx, ny});
            } else {
                if (dist[wall_break][nx][ny]) continue;

                dist[wall_break][nx][ny] = dist[wall_break][x][y] + 1;
                Q.push({wall_break, nx, ny});
            }
        }
    }

    int ans = MX;

    for (int i = 0; i < 2; i++) {
        if (dist[i][N - 1][M - 1]) {
            ans = min(ans, dist[i][N - 1][M - 1]);
        }
        // for (int j = 0; j < N; j++) {
        //     for (int k = 0; k < M; k++) {
        //         cout << dist[i][j][k] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
    // cout << '\n';

    if (ans == MX)
        cout << -1;
    else
        cout << ans;
}