#include <bits/stdc++.h>
using namespace std;

int f_dist[1001][1001];
int s_dist[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int w, h;
        cin >> w >> h;
        queue<pair<int, int>> FQ;
        queue<pair<int, int>> SQ;

        for (int i = 0; i < h; i++) {
            fill(f_dist[i], f_dist[i] + w, -1);
            fill(s_dist[i], s_dist[i] + w, -1);
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char val;
                cin >> val;

                if (val == '#') {
                    f_dist[i][j] = 0;
                    s_dist[i][j] = 0;
                }

                if (val == '*') {
                    FQ.push({i, j});
                    f_dist[i][j] = 0;
                }
                if (val == '@') {
                    SQ.push({i, j});
                    s_dist[i][j] = 0;
                }
            }
        }

        while (!FQ.empty()) {
            int x, y;
            tie(x, y) = FQ.front();
            FQ.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (f_dist[nx][ny] != -1) continue;

                f_dist[nx][ny] = f_dist[x][y] + 1;
                FQ.push({nx, ny});
            }
        }

        bool escape = false;
        int ans = 0;
        while (!SQ.empty() && !escape) {
            int x, y;
            tie(x, y) = SQ.front();
            SQ.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                    ans = s_dist[x][y] + 1;
                    escape = true;
                    break;
                };
                if (s_dist[nx][ny] != -1) continue;
                if (f_dist[nx][ny] != -1 && s_dist[x][y] + 1 >= f_dist[nx][ny]) continue;

                s_dist[nx][ny] = s_dist[x][y] + 1;
                SQ.push({nx, ny});
            }
        }

        if (escape) {
            cout << ans << '\n';
        } else {
            cout << "IMPOSSIBLE" << '\n';
        }
    }
}