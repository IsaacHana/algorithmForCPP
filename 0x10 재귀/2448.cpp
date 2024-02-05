#include <bits/stdc++.h>
using namespace std;

const int MX = 1024 * 3;
char board[MX][2 * MX - 1];

void stars(int N, int x, int y) {
    board[x][y] = '*';
    board[x + 1][y - 1] = '*';
    board[x + 1][y + 1] = '*';
    for (int i = y - 2; i <= y + 2; i++) {
        board[x + 2][i] = '*';
    }
}

void recursion(int N, int x, int y) {
    // base case
    if (N == 3) {
        stars(N, x, y);
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
    for (int i = 0; i < N; i++) {
        fill(board[i], board[i] + 2 * N - 1, ' ');
    }

    // stars(3, 0, 2);
    // stars(N, 0, N - 1);

    recursion(N, 0, N - 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}