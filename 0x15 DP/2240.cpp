#include <bits/stdc++.h>
using namespace std;

int t[1002];
int dp[1002][32][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T, W;
    cin >> T >> W;

    // w, curPos  \ T : 0 1 2 3 4 5 6 7
    // 0, 1     (start)'0 0 1 2 2 2 3 4
    // 0, 2             0 0 0 0 0 0 0 0
    // 1, 1             0 0 1 2 2 2 3 4
    // 1, 2             0 1 1 1 3 4 4 4
    // 2, 1             0 0 2 3 3 3 5 6
    // 2, 2             0 0 0 1 3 4 4 4

    for (int i = 1; i <= T; i++) cin >> t[i];

    for (int i = 1; i <= T; i++) {
        if (t[i] == 1) {
            dp[i][0][1] = dp[i - 1][0][1] + 1;
        } else {
            dp[i][0][1] = dp[i - 1][0][1];
        }

        for (int j = 1; j <= W; j++) {
            if (i < j) break;

            if (t[i] == 1) {
                dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]) + 1;
                dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]);
            } else {
                dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]);
                dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + 1;
            }
        }
    }
    for (int i = 0; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            cout << dp[i][j][1] << " " << dp[i][j][2] << '\n';
        }
        cout << '\n';
    }
    int ans = 0;

    for (int j = 0; j <= W; j++) {
        ans = max({ans, dp[T][j][1], dp[T][j][2]});
    }

    cout << ans << '\n';
}