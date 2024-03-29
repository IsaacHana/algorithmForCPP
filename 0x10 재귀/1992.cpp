#include <bits/stdc++.h>
using namespace std;

string board[64];

bool valid(int N, int x, int y) {
    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (board[x][y] != board[i][j]) return false;
        }
    }

    return true;
}

void recursion(int N, int x, int y) {
    // base case
    if (valid(N, x, y)) {
        cout << board[x][y];
        return;
    }
    int n = N / 2;
    cout << '(';

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            recursion(n, x + i * n, y + j * n);
        }
    }

    cout << ')';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    recursion(N, 0, 0);
}