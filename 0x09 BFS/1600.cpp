#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int K, W, H;
int board[201][201];
int dist[201][201][32];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int horse_dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int horse_dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool isVaild(int x, int y, int k) {
    if (x < 1 || x > H || y < 1 || y > W) return false;
    if (board[x][y] == 1) return false;
    if (dist[x][y][k] != 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> W >> H;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> board[i][j];
        }
    }
    queue<tuple<int, int, int>> Q;
    Q.push({1, 1, K});
    dist[1][1][K] = 1;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        int x, y, k;
        tie(x, y, k) = cur;

        if (x == H && y == W) {
            dist[x][y][k];
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!isVaild(nx, ny, k)) continue;
            dist[nx][ny][k] = dist[x][y][k] + 1;
            Q.push({nx, ny, k});
        }
        if (k < 1) continue;
        for (int i = 0; i < 8; i++) {
            int nx = x + horse_dx[i];
            int ny = y + horse_dy[i];
            if (!isVaild(nx, ny, k - 1)) continue;
            dist[nx][ny][k - 1] = dist[x][y][k] + 1;
            Q.push({nx, ny, k - 1});
        }
    }
    int ans = INF;

    for (int k = 0; k <= K; k++) {
        if (dist[H][W][k]) {
            ans = min(ans, dist[H][W][k]);
        }
    }

    if (ans == INF)
        cout << -1;
    else
        cout << ans - 1;
}