#include <bits/stdc++.h>
using namespace std;

char board[12][12];

int N, M;
const int INF = (~0U >> 2);
int ans = INF;

void rotate() {
    char tmp[12][12] = {};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            tmp[i][j] = board[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = tmp[N - 1 - j][i];
        }
    }

    swap(N, M);

    cout << N << " : " << M << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool isGoal = false;

void tilt() {
    for (int i = 1; i < N - 1; i++) {
        string tilted = board[i];
        for (int j = 1; j < M - 1; j++) {
            if (board[i][j] == '#') tilted[j] = '#';
            if (board[i][j] == 'R') tilted[j] = '.';
            if (board[i][j] == 'B') tilted[j] = '.';
        }
        int idx = 1;

        for (int j = 1; j < M - 1; j++) {
            if (board[i][j] == '.') continue;
            if (board[i][j] == '#') {
                idx = j + 1;
                continue;
            }

            if (tilted[idx] == '.') {
                tilted[idx++] = board[i][j];
                board[i][j] == '.';
            }

            if (tilted[idx] == 'O') {
                isGoal = true;
                board[i][j] == '.';
            }
        }
        for (int j = 1; j < M - 1; j++) {
            board[i][j] = tilted[j];
        }
    }
}

int arr[10];

void dfs(int depth) {
    if (ans <= depth) return;

    if (isGoal) {
        ans = min(ans, depth);
        return;
    }

    if (depth >= 10) {
        // for (int i = 0; i < 10; i++) {
        //     cout << arr[i] << ' ';
        // }
        // cout << '\n';
        return;
    }

    for (int i = 0; i < 4; i++) {
        char copy[12][12];
        cout << i << '\n';
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                copy[i][j] = board[i][j];
            }
        }

        for (int j = 0; j < i; j++) {
            rotate();
        }
        tilt();
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        arr[depth] = i;
        dfs(depth + 1);
        isGoal = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                board[i][j] = copy[i][j];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    // tilt();
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // rotate();
    // rotate();
    // tilt();

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    dfs(0);
    if (ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}