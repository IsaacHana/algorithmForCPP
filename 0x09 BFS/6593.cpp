#include <bits/stdc++.h>
using namespace std;

int dist[31][31][31];

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int L, R, C;
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0) break;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                fill(dist[i][j], dist[i][j] + C, -1);
            }
        }

        queue<tuple<int, int, int>> Q;
        int ez, ex, ey;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                string str;
                cin >> str;
                for (int k = 0; k < C; k++) {
                    int val = str[k];
                    if (val == '#') {
                        dist[i][j][k] = 0;
                    }
                    if (val == 'S') {
                        Q.push({i, j, k});
                        dist[i][j][k] = 0;
                    }
                    if (val == 'E') {
                        ez = i;
                        ex = j;
                        ey = k;
                    }
                }
            }
        }

        bool escape = false;
        while (!Q.empty() && !escape) {
            int z, x, y;
            tie(z, x, y) = Q.front();
            Q.pop();

            for (int dir = 0; dir < 6; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int nz = z + dz[dir];

                if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (dist[nz][nx][ny] != -1) continue;

                dist[nz][nx][ny] = dist[z][x][y] + 1;

                if (nz == ez && nx == ex && ny == ey) {
                    escape = true;
                    break;
                }

                Q.push({nz, nx, ny});
            }
        }

        if (escape)
            cout << "Escaped in " << dist[ez][ex][ey] << " minute(s)." << '\n';
        else
            cout << "Trapped!" << '\n';
    }
}