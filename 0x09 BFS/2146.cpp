#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int dist[101][101];
bool vis[101][101];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue;
            idx++;

            queue<pair<int, int>> Q;
            Q.push({i, j});

            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                board[cur.first][cur.second] = idx;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny]) continue;
                    if (board[nx][ny] == 0) continue;

                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        fill(dist[i], dist[i] + N, -1);
    }

    queue<pair<int, int>> Q;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                dist[i][j] = 0;
                Q.push({i, j});
            }
        }
    }

    int ans = 987654321;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[cur.first][cur.second] == board[nx][ny]) continue;

            if (board[nx][ny]) {
                ans = min(ans, dist[nx][ny] + dist[cur.first][cur.second]);  // 각각의 섬에 떨어진 위치를 의 합
                continue;
            }
            board[nx][ny] = board[cur.first][cur.second];
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }

    cout << ans;
}