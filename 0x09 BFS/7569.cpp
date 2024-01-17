#include <bits/stdc++.h>
using namespace std;

int board[101][101][101];

int dz[6] = {1, 0, 0, -1, 0, 0};
int dx[6] = {0, 1, 0, 0, -1, 0};
int dy[6] = {0, 0, 1, 0, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    int N, M, H;
    cin >> M >> N >> H;

    int total = H * M * N;

    queue<tuple<int, int, int>> Q;
    int val;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> val;
                board[i][j][k] = val;

                if (val == 1) {
                    Q.push({i, j, k});
                    total--;
                }
                if (val == -1) {
                    total--;
                }
            }
        }
    }

    while (!Q.empty()) {
        int z, x, y;
        tie(z, x, y) = Q.front();
        Q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nz][nx][ny] == 0) {
                total--;
                board[nz][nx][ny] = board[z][x][y] + 1;
                ans = max(ans, board[nz][nx][ny] - 1);
                Q.push({nz, nx, ny});
            }
        }
    }

    if (total) {
        cout << -1;
    } else {
        cout << ans;
    }
}