#include <bits/stdc++.h>
using namespace std;

const int MX = 3 * 1024;
char board[MX + 1][MX * 2 - 1];

void stars(int x, int y) {
    board[x][y] = '*';

    board[x + 1][y - 1] = '*';
    board[x + 1][y + 1] = '*';

    for (int i = y - 2; i <= y + 2; i++) {
        board[x + 2][i] = '*';
    }
}

void recursion(int N, int x, int y) {
    if (N == 3) {
        stars(x, y);
        return;
    }

    int n = N / 2;

    recursion(n, x, y);
    recursion(n, x + n, y - n);
    recursion(n, x + n, y + n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    // 1. 가운데 빈 삼각형을 만들 수 있다.
    // stars(0, N - 1);
    // 2. 나머지 부분도 다 1. 처럼 할 수 있다.
    // stars(0 + N / 2, N - 1 - N / 2);
    // stars(0 + N / 2, N - 1 + N / 2);

    for (int i = 0; i < N; i++) {
        fill(board[i], board[i] + 2 * N - 1, ' ');
    }

    recursion(N, 0, N - 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}