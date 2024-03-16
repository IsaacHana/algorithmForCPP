#include <bits/stdc++.h>
using namespace std;

int T[1'500'002];
int P[1'500'002];
int dp[1'500'002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i], dp[i - 1]);

        if (i + T[i] - 1 > N) continue;

        dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';

    cout << max(dp[N], dp[N + 1]) << '\n';
}
