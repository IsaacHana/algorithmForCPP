#include <bits/stdc++.h>
using namespace std;

int board[21][21];
int N;
int mx = 0;

void print_board() {
    cout << "=================\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void max_value() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mx = max(mx, board[i][j]);
        }
    }
}

void rotate() {
    int tmp[21][21];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = tmp[N - 1 - j][i];
        }
    }
}

void tilt() {
    for (int i = 0; i < N; i++) {
        int tilted[21] = {};
        int idx = 0;
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) continue;

            if (tilted[idx] == 0) {
                tilted[idx] = board[i][j];
            } else if (tilted[idx] == board[i][j]) {
                tilted[idx++] *= 2;  // merge
            } else {
                tilted[++idx] = board[i][j];
            }
        }
        for (int j = 0; j < N; j++) {
            board[i][j] = tilted[j];
        }
    }
}

void dfs(int depth) {
    if (depth == 5) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int tmp[21][21] = {};

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                tmp[i][j] = board[i][j];
            }
        }

        for (int j = 0; j < i; j++) {
            rotate();
        }
        tilt();
        // print_board();
        max_value();
        dfs(depth + 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[i][j] = tmp[i][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0);
    // tilt();
    // print_board();
    cout << mx;
}