#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        int sticker[2][n] = {};
        int dp[2][n] = {};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> sticker[j][i];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                int v = 0;
                if (i > 1) v = max(dp[0][i - 2], dp[1][i - 2]);
                if (i > 0) v = max(v, dp[1 - j][1 - j]);
                dp[j][i] = v + sticker[j][i];
            }
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
}