#include <bits/stdc++.h>
using namespace std;

int board[501][501];
int dp[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 7
    // 10 15
    // 18 11(16) 15
    // 20 25(18) 20(19) 19

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> board[i][j];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < i + 1; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i + 1) {
                board[i][j] += board[i - 1][j];
            } else {
                board[i][j] += max(board[i - 1][j - 1], board[i - 1][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, board[n - 1][i]);
    }
    cout << ans << '\n';
}