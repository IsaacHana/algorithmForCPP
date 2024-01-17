#include <bits/stdc++.h>
using namespace std;

bool vis[51][51];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N, M, K;
    cin >> T;
    while (T--) {
        cin >> M >> N >> K;
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            fill(vis[i], vis[i] + M, true);
        }

        queue<pair<int, int>> Q;
        int X, Y;
        while (K--) {
            cin >> Y >> X;
            vis[X][Y] = false;
            Q.push({X, Y});
        }

        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            if (vis[cur.first][cur.second]) continue;
            vis[cur.first][cur.second] = true;
            cnt++;

            queue<pair<int, int>> Q2;
            Q2.push({cur.first, cur.second});
            while (!Q2.empty()) {
                auto cur2 = Q2.front();
                Q2.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur2.first + dx[dir];
                    int ny = cur2.second + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (vis[nx][ny]) continue;

                    vis[nx][ny] = true;
                    Q2.push({nx, ny});
                }
            }
        }

        cout << cnt << '\n';
    }
}