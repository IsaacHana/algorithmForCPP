#include <bits/stdc++.h>
using namespace std;
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dist[305][305];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int I;
        cin >> I;
        for (int i = 0; i < I; i++) {
            fill(dist[i], dist[i] + I, -1);
        }

        int SX, SY;
        cin >> SX >> SY;

        queue<pair<int, int>> Q;
        Q.push({SX, SY});
        dist[SX][SY] = 0;

        int EX, EY;
        cin >> EX >> EY;
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 8; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= I || ny < 0 || ny >= I) continue;
                if (dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }

        cout << dist[EX][EY] << '\n';
    }
}