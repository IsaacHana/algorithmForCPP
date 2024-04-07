#include <bits/stdc++.h>
using namespace std;

int board[52][52];

int R, C, T;
int up = 0, down = 0;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int cdx[4] = {0, 1, 0, -1};

void spread(int i, int j) {
    if (board[i][j] == 0) return;

    int total = 0;

    for (int dir = 0; dir < 4; dir++) {
        int nx = i + dx[dir];
        int ny = j + dy[dir];

        if (nx < 0 || nx >= R || ny < 0 || ny > C) continue;
        if (board[nx][ny] == -1) continue;
        int amount = board[i][j] / 5;
        board[nx][ny] += amount;
        total += amount;
    }

    board[i][j] -= total;
}

void counter_clock(int i, int j, int dir, int prev) {
    if (board[i][j] == -1) {
        return;
    }

    int tmp = board[i][j];
    board[i][j] = prev;

    int nx = i + dx[dir];
    int ny = j + dy[dir];

    if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
        dir++;
        nx = i + dx[dir];
        ny = j + dy[dir];

        counter_clock(nx, ny, dir, tmp);
    } else {
        counter_clock(nx, ny, dir, tmp);
    }
}

void clock(int i, int j, int dir, int prev) {
    if (board[i][j] == -1) {
        return;
    }

    int tmp = board[i][j];
    board[i][j] = prev;

    int nx = i + cdx[dir];
    int ny = j + dy[dir];

    if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
        dir++;
        nx = i + cdx[dir];
        ny = j + dy[dir];

        counter_clock(nx, ny, dir, tmp);
    } else {
        counter_clock(nx, ny, dir, tmp);
    }
}

void work() {
    // CC
    counter_clock(up, 1, 0, 0);
    // C
    clock(down, 1, 0, 0);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> T;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                if (up == 0) {
                    up = i;
                } else {
                    down = i;
                }
            }
        }
    }
    // 1. 미세먼지 확산
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == -1) continue;
            spread(i, j);
        }
    }

    // 2. 기계 작동
    // work();

    cout << '\n';
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    work();
    cout << '\n';
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}