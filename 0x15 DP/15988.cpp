#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'009;

int dp[1'000'002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1 : 1
    // 2 : 1 + 1, 2
    // 3 : 1 + 1 + 1, 1 + 2, 2 + 1, 3
    // 4 : 1 + 1 + 1 + 1 (dp[3][1] + 1), 1 + 2 + 1(dp[3][2] + 1), 2 + 1 + 1 (dp[3][3] + 1), 3 + 1(dp[3][4] + 1)
    // 1 + 1 + 2(dp2[2][1] + 2), 2 + 2(dp[2][2] + 2)
    // 1 + 3 (dp[1][1] + 3)
    vector<int> vec;
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    int mx = 0;
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vec.push_back(n);
        mx = max(mx, n);
    }

    for (int i = 4; i <= mx; i++) {
        for (int j = 1; j <= 3; j++) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    for (auto v : vec) {
        cout << dp[v] << '\n';
    }
}