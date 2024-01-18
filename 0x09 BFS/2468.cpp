#include <bits/stdc++.h>
using namespace std;

int board[101][101];
bool vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, mx = 1;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            mx = max(mx, board[i][j]);
        }
    }
    int mx_cnt = 0;
    while (mx--) {
        for (int i = 0; i < N; i++) {
            fill(vis[i], vis[i] + N, false);
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (mx >= board[i][j]) vis[i][j] = true;
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (vis[i][j]) continue;
                cnt++;

                queue<pair<int, int>> Q;
                Q.push({i, j});
                vis[i][j] = true;

                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (vis[nx][ny]) continue;

                        vis[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        mx_cnt = max(mx_cnt, cnt);
    }
    cout << mx_cnt;
}