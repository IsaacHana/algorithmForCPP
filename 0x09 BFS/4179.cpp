#include <bits/stdc++.h>
using namespace std;

int C, R;
string maze[1002];
int f_dist[1002][1002];
int j_dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        fill(f_dist[i], f_dist[i] + C, -1);
        fill(j_dist[i], j_dist[i] + C, -1);
    }
    for (int i = 0; i < R; i++) {
        cin >> maze[i];
    }

    queue<pair<int, int>> FQ;
    queue<pair<int, int>> JQ;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (maze[i][j] == 'F') {
                FQ.push({i, j});
                f_dist[i][j] = 0;
            }
            if (maze[i][j] == 'J') {
                JQ.push({i, j});
                j_dist[i][j] = 0;
            }
        }
    }

    while (!FQ.empty()) {
        auto cur = FQ.front();
        FQ.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (f_dist[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
            f_dist[nx][ny] = f_dist[cur.first][cur.second] + 1;
            FQ.push({nx, ny});
        }
    }

    while (!JQ.empty()) {
        auto cur = JQ.front();
        JQ.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            int exp = j_dist[cur.first][cur.second] + 1;

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << exp;
                return 0;
            }
            if (j_dist[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
            if (f_dist[nx][ny] != -1 && f_dist[nx][ny] <= exp) continue;
            j_dist[nx][ny] = exp;
            JQ.push({nx, ny});
        }
    }

    cout << "IMPOSSIBLE";
}