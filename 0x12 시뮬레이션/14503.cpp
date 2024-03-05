#include <bits/stdc++.h>
using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

int board[52][52];
int N, M, r, c, d;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 0;

void run() {
    while (true) {
        // 1.
        if (board[r][c] == 0) {
            board[r][c] = 2;
            ans++;
        }

        // 2, 3
        bool flag = false;
        for (int dir = 0; dir < 4; dir++) {
            int nx = r + dx[dir];
            int ny = c + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == 0) flag = true;
        }

        // 3
        if (flag) {
            // 3 - 1
            d = (d + 3) % 4;
            // 3 - 2
            int fx = r + dx[d];
            int fy = c + dy[d];
            if (fx < 0 || fx >= N || fy < 0 || fy >= M) {
                continue;
            }
            // 3-2
            if (board[fx][fy] == 0) r = fx, c = fy;
        }
        // 2
        else {
            int back = (d + 2) % 4;
            int bx = r + dx[back];
            int by = c + dy[back];
            // 2-2
            if (bx < 0 || bx >= N || by < 0 || by >= M || board[bx][by] == 1) {
                return;
            }
            // 2-1
            r = bx, c = by;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    run();

    cout << ans << '\n';
}