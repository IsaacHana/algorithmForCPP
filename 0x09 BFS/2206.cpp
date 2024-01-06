#include <bits/stdc++.h>
using namespace std;

int board[1002][1002];
int dist[1002][1002][2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            int num = str[j] - '0';
            board[i][j] = num;
        }
    }

    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 1});
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    while (!Q.empty()) {
        int x, y, boom;
        tie(x, y, boom) = Q.front();
        Q.pop();

        if (x == N - 1 && y == M - 1) {
            cout << dist[N - 1][M - 1][boom];
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny][boom]) continue;

            if (board[nx][ny] == 0) {
                dist[nx][ny][boom] = dist[x][y][boom] + 1;
                Q.push({nx, ny, boom});
            } else {
                if (boom == 0) continue;
                dist[nx][ny][boom - 1] = dist[x][y][boom] + 1;
                Q.push({nx, ny, boom - 1});
            }
        }
    }

    cout << -1;
}