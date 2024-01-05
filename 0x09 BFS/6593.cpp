#include <bits/stdc++.h>
using namespace std;

string SBB[32][32];
int dist[32][32][32];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int L, R, C;
        cin >> L >> R >> C;
        if (L == 0 && R == 0 & C == 0) break;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                cin >> SBB[i][j];
            }
        }

        queue<tuple<int, int, int>> Q;
        tuple<int, int, int> end;

        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                for (int k = 0; k < C; k++) {
                    char c = SBB[i][j][k];
                    if (c == 'S') {
                        Q.push({i, j, k});
                        dist[i][j][k] = 0;
                    } else if (c == 'E') {
                        end = {i, j, k};
                        dist[i][j][k] = -1;
                    } else if (c == '#') {
                        dist[i][j][k] = 0;
                    } else if (c == '.') {
                        dist[i][j][k] = -1;
                    }
                }
            }
        }
        bool escape = false;
        while (!Q.empty() && !escape) {
            auto cur = Q.front();
            Q.pop();

            int x, y, z;
            tie(x, y, z) = cur;

            for (int dir = 0; dir < 6; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int nz = z + dz[dir];

                if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C) continue;
                if (dist[nx][ny][nz] != -1) continue;

                dist[nx][ny][nz] = dist[x][y][z] + 1;
                Q.push({nx, ny, nz});

                if (SBB[nx][ny][nz] == 'E') {
                    escape = true;
                    break;
                }
            }
        }

        if (escape)
            cout << "Escaped in " << dist[get<0>(end)][get<1>(end)][get<2>(end)] << " minute(s).\n";
        else
            cout << "Trapped!\n";
    }
}