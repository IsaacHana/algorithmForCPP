    #include <bits/stdc++.h>
    using namespace std;

    int f_dist[1002][1002];
    int s_dist[1002][1002];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int T;
        cin >> T;
        while (T--) {
            int w, h;
            cin >> h >> w;
            queue<pair<int, int>> FQ;
            queue<pair<int, int>> SQ;

            for (int i = 0; i < w; i++) {
                fill(f_dist[i], f_dist[i] + h, -1);
                fill(s_dist[i], s_dist[i] + h, -1);
                for (int j = 0; j < h; j++) {
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
                auto cur = FQ.front();
                FQ.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
                    if (f_dist[nx][ny] >= 0) continue;
                    f_dist[nx][ny] = f_dist[cur.first][cur.second] + 1;
                    FQ.push({nx, ny});
                }
            }

            bool escape = false;
            while (!SQ.empty() && !escape) {
                auto cur = SQ.front();
                SQ.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    int exp = s_dist[cur.first][cur.second] + 1;
                    if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                        escape = true;
                        cout << exp << '\n';
                        break;
                    }
                    if (s_dist[nx][ny] >= 0) continue;
                    if (f_dist[nx][ny] != -1 && f_dist[nx][ny] <= exp) continue;
                    s_dist[nx][ny] = exp;
                    SQ.push({nx, ny});
                }
            }
            if (!escape) cout << "IMPOSSIBLE\n";
        }
    }