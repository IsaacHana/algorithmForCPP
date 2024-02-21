#include <bits/stdc++.h>
using namespace std;
int N, M, K;
int R, C;
int laptop[40][40];
int sticker[10][10];

void rotate() {
    int tmp[10][10];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < R; j++) {
            sticker[i][j] = tmp[R - 1 - j][i];
        }
    }

    swap(R, C);
    // cout << "====rotate====" << '\n';
    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << sticker[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

bool valid(int sx, int sy) {
    // cout << "====valid====\n";
    // bool falg = true;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // cout << laptop[sx + i][sy + j] << ' ';
            if (laptop[sx + i][sy + j] == 1 && sticker[i][j] == 1) {
                // falg = false;
                return false;
            }
        }
        // cout << '\n';
    }

    return true;
}

void stick(int sx, int sy) {
    // cout << "=====stick=====\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // cout << sticker[sx + i][sy + j] << ' ';
            if (sticker[i][j] == 1) {
                laptop[sx + i][sy + j]++;
            }
        }
        // cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int k = 0; k < K; k++) {
        cin >> R >> C;
        // cout << "====sticker====\n";
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> sticker[i][j];
                // cout << sticker[i][j] << ' ';
            }
            // cout << '\n';
        }

        bool flag = false;
        for (int dir = 0; dir < 4; dir++) {
            for (int i = 0; i <= N - R; i++) {
                for (int j = 0; j <= M - C; j++) {
                    if (valid(i, j)) {
                        flag = true;
                        stick(i, j);
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
            rotate();
        }

        // cout << "=======laptop=======\n";
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << laptop[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cnt += laptop[i][j];
        }
    }

    cout << cnt << '\n';
}