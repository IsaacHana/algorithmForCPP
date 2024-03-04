#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

const int H = 5;
const int N = 5;
const int M = 5;

int cube[H][N][M];
int new_cube[H][N][M];
bool vis[H];

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};

void rotate(int h, int dir) {
    if (dir == 0)
        return;
    else {
        int tmp[N][M];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                tmp[i][j] = new_cube[h][i][j];
            }
        }
        if (dir == 1) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    new_cube[h][i][j] = tmp[N - 1 - j][i];
                }
            }
        } else if (dir == 2) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    new_cube[h][i][j] = tmp[M - 1 - i][N - 1 - j];
                }
            }
        } else if (dir == 3) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    new_cube[h][N - 1 - j][i] = tmp[i][j];
                }
            }
        }
    }
}

int ans = INF;

int bfs() {
    int dist[H][N][M] = {};

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    dist[0][0][0] = 0;

    while (!q.empty()) {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];

            if (nx < 0 || nx >= H || ny < 0 || ny >= N || nz < 0 || nz >= M) continue;
            if (new_cube[nx][ny][nz] == 0) continue;
            if (dist[nx][ny][nz]) continue;

            dist[nx][ny][nz] = dist[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }

    return dist[H - 1][N - 1][M - 1];
}

void dfs2(int depth) {
    if (depth > 0) {
        if (new_cube[0][0][0] == 0) return;
    }
    if (depth == H) {
        if (new_cube[H - 1][N - 1][M - 1] == 0) return;
        // cout << "==========new==========\n";
        // for (int i = 0; i < H; i++) {
        //     for (int j = 0; j < N; j++) {
        //         for (int k = 0; k < M; k++) {
        //             cout << new_cube[i][j][k] << ' ';
        //         }
        //         cout << '\n';
        //     }
        //     cout << '\n';
        // }
        int result = bfs();
        if (result) {
            ans = min(ans, result);
        }
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        rotate(depth, dir);
        dfs2(depth + 1);
    }
}

void dfs(int depth) {
    if (depth > 0) {
        if (new_cube[0][0][0] == 0 && new_cube[0][N - 1][0] == 0 && new_cube[0][0][M - 1] == 0 && new_cube[0][N - 1][M - 1] == 0) return;
    }

    if (depth == H) {
        // cout << "==========new==========\n";
        // for (int i = 0; i < H; i++) {
        //     for (int j = 0; j < N; j++) {
        //         for (int k = 0; k < M; k++) {
        //             cout << new_cube[i][j][k] << ' ';
        //         }
        //         cout << '\n';
        //     }
        //     cout << '\n';
        // }

        dfs2(0);

        return;
    }

    for (int i = 0; i < H; i++) {
        if (vis[i]) continue;

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                new_cube[depth][j][k] = cube[i][j][k];
            }
        }
        vis[i] = true;
        dfs(depth + 1);
        vis[i] = false;
        for (int j = 0; j < N; j++) {
            fill(new_cube[depth][j], new_cube[depth][j] + M, 0);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> cube[i][j][k];
            }
        }
    }
    // cout << "=================\n";
    // rotate(0, 2);
    // for (int j = 0; j < N; j++) {
    //     for (int k = 0; k < M; k++) {
    //         cout << cube[0][j][k] << ' ';
    //     }
    //     cout << '\n';
    // }

    dfs(0);
    if (ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}