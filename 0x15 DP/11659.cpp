#include <bits/stdc++.h>
using namespace std;

int board[100'001];
int dp[100'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> board[i];
    }

    dp[1] = board[1];

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + board[i];
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << dp[i] << ' ';
    // }

    int i, j;
    while (M--) {
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << '\n';
    }
}