#include <bits/stdc++.h>
using namespace std;
// 1 3 9 27 81 273 819 2457 7371
bool board[2458][2458];

void stars(int n, int x, int y) {
    for (int i = x + n; i < x + 2 * n; i++) {
        for (int j = y + n; j < y + 2 * n; j++) {
            board[i][j] = 1;
        }
    }
}

void recursion(int N, int x, int y) {
    int n = N / 3;

    stars(n, x, y);

    if (n == 1) {
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            recursion(n, x + i * n, y + j * n);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    // stars(3, 0, 0);
    // stars(3, 3, 0);
    // stars(9, 0, 0);

    recursion(N, 0, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!board[i][j])
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
}
