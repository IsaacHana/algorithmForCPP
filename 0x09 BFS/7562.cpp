#include <bits/stdc++.h>
using namespace std;

int dist[301][301];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, l;
    cin >> T;
    while (T--) {
        cin >> l;
        queue<pair<int, int>> Q;
        int sx, sy, ex, ey;
        cin >> sx >> sy;
        cin >> ex >> ey;

        for (int i = 0; i < l; i++) {
            fill(dist[i], dist[i] + l, -1);
        }

        Q.push({sx, sy});
        dist[sx][sy] = 0;

        while (dist[ex][ey] == -1) {
            int x, y;
            tie(x, y) = Q.front();
            Q.pop();

            for (int dir = 0; dir < 8; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
                if (dist[nx][ny] != -1) continue;

                dist[nx][ny] = dist[x][y] + 1;
                Q.push({nx, ny});
            }
        }

        cout << dist[ex][ey] << '\n';
    }
}