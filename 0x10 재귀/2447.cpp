#include <bits/stdc++.h>
using namespace std;
char board[2460][2460];

void recursion(int N, int x, int y) {
    // base case
    if (N == 1) {
        board[x][y] = '*';
        return;
    }

    int n = N / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue;
            recursion(n, x + i * n, y + j * n);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        fill(board[i], board[i] + N, ' ');
    }

    recursion(N, 0, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}