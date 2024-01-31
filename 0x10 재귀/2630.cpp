#include <bits/stdc++.h>
using namespace std;

bool board[129][129];
int cntArr[2];

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
        cntArr[board[x][y]] += 1;
        return;
    }

    int n = N / 2;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
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
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // cout << valid(8, 0, 0) << '\n';  // 0
    // cout << valid(2, 0, 0) << '\n';  // 1

    recursion(N, 0, 0);

    for (auto cnt : cntArr) {
        cout << cnt << '\n';
    }
}