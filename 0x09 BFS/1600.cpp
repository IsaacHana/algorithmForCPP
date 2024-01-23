#include <bits/stdc++.h>
using namespace std;

const int MX = 987654321;
int board[201][201];
int dist[31][201][201];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int hx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int hy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, W, H;
    cin >> K >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
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

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (board[nx][ny]) continue;
            if (dist[k][nx][ny]) continue;

            dist[k][nx][ny] = dist[k][x][y] + 1;
            Q.push({k, nx, ny});
        }

        if (k <= 0) continue;

        for (int dir = 0; dir < 8; dir++) {
            int nx = x + hx[dir];
            int ny = y + hy[dir];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (board[nx][ny]) continue;
            if (dist[k - 1][nx][ny]) continue;

            dist[k - 1][nx][ny] = dist[k][x][y] + 1;
            Q.push({k - 1, nx, ny});
        }
    }

    int ans = MX;

    for (int i = 0; i <= 30; i++) {
        if (dist[i][H - 1][W - 1]) ans = min(ans, dist[i][H - 1][W - 1]);
    }

    if (ans == MX) {
        cout << -1;
    } else {
        cout << ans - 1;
    }
}