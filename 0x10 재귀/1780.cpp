#include <bits/stdc++.h>
using namespace std;

const int MX = 2187;
int cnt[3];
int board[MX + 1][MX + 1];

bool valid(int N, int x, int y) {
    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (board[x][y] != board[i][j]) return false;
        }
    }
    return true;
}

void recursion(int N, int x, int y) {
    if (valid(N, x, y)) {
        cnt[board[x][y] + 1]++;
        return;
    }

    int n = N / 3;

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

    // init
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // cout << valid(3, 0, 0) << '\n';      // 1
    // cout << valid(3, 3 * 2, 0) << '\n';  // 0

    recursion(N, 0, 0);

    for (auto val : cnt) {
        cout << val << '\n';
    }
}