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

    int ans = 987654321;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue;

            queue<pair<int, int>> Q;
            queue<pair<int, int>> GQ;

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
                    if (board[nx][ny] == 0 && !vis[nx][ny]) {
                        GQ.push({cur.first, cur.second});
                        continue;
                    }
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
            while (!GQ.empty()) {
                bool complete = false;
                int qsize = GQ.size();
                for (int i = 0; i < qsize; i++) {
                    auto cur = GQ.front();
                    GQ.pop();
                    if (dist[cur.first][cur.second] >= ans) complete = true;
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        int exp = dist[cur.first][cur.second] + 1;
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (vis[nx][ny]) continue;
                        if (dist[nx][ny]) continue;
                        if (board[nx][ny] == 1 || exp > ans) {
                            complete = true;
                            ans = min(ans, dist[cur.first][cur.second]);
                        }
                        dist[nx][ny] = exp;
                        GQ.push({nx, ny});
                    }
                }
                if (complete) break;
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = 0;
                }
            }
        }
    }
    cout << ans;
}