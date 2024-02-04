#include <bits/stdc++.h>
using namespace std;

const int MX = 2200;
int board[MX][MX];
int cntArr[3];
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
        cntArr[board[x][y] + 1] += 1;
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
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    recursion(N, 0, 0);

    for (int cnt : cntArr) {
        cout << cnt << '\n';
    }
}