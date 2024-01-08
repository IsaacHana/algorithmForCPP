#include <bits/stdc++.h>
using namespace std;

int board[301][301];
bool vis[301][301];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                total++;
            }
        }
    }

    int time = 0;
    while (total > 0) {
        int ice_chunk = 0;
        // 찾아서 녹이기
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] < 1 || vis[i][j]) continue;
                ice_chunk++;
                if (ice_chunk > 1) {
                    cout << time;
                    return 0;
                }
                queue<pair<int, int>> Q;
                queue<tuple<int, int, int>> Q2;

                Q.push({i, j});
                vis[i][j] = true;

                // 주변 바다 계산
                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    int cnt = 0;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (vis[nx][ny]) continue;
                        if (board[nx][ny] < 1) {
                            cnt++;
                            continue;
                        }
                        vis[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                    Q2.push({cur.first, cur.second, cnt});
                }
                // 빙산 녹이기
                while (!Q2.empty()) {
                    auto cur = Q2.front();
                    Q2.pop();

                    int x, y, cnt;
                    tie(x, y, cnt) = cur;

                    board[x][y] -= cnt;
                    if (board[x][y] < 1) total--;
                }
            }
        }

        // 방문 초기화
        for (int i = 0; i < N; i++) {
            fill(vis[i], vis[i] + M, false);
        }

        time++;
    }

    cout << 0;
}