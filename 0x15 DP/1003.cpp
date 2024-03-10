#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    // 0 1 2 3 4 5 6
    // 1 0 1 1 2 3
    // 0 1 1 2 3 5

    int val, mx = 0;
    queue<int> q;

    while (T--) {
        cin >> val;
        q.push(val);
        mx = max(mx, val);
    }
    int dp[2][42];
    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[0][1] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= mx; i++) {
        dp[0][i] = dp[0][i - 1] + dp[0][i - 2];
        dp[1][i] = dp[1][i - 1] + dp[1][i - 2];
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        cout << dp[0][cur] << ' ' << dp[1][cur] << '\n';
    }
}