#include <bits/stdc++.h>
using namespace std;

string board[1001];
int J_dist[1001][1001];
int F_dist[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int R, C;
    cin >> R >> C;

    queue<pair<int, int>> JQ;
    queue<pair<int, int>> FQ;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'J') {
                JQ.push({i, j});
                J_dist[i][j] = 1;
            }
            if (board[i][j] == 'F') {
                FQ.push({i, j});
                F_dist[i][j] = 1;
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
            if (board[nx][ny] == '#') continue;
            if (F_dist[nx][ny]) continue;

            F_dist[nx][ny] = F_dist[cur.first][cur.second] + 1;
            FQ.push({nx, ny});
        }
    }

    while (!JQ.empty()) {
        auto cur = JQ.front();
        JQ.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            int exp = J_dist[cur.first][cur.second] + 1;

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
                cout << J_dist[cur.first][cur.second] << '\n';
                return 0;
            }

            if (board[nx][ny] == '#') continue;
            if (J_dist[nx][ny]) continue;
            if (F_dist[nx][ny] && exp >= F_dist[nx][ny]) continue;

            J_dist[nx][ny] = exp;
            JQ.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}