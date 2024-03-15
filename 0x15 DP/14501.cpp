#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[17];
int dp[17];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, T, P;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T >> P;
        arr[i] = {T, P};
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i], dp[i - 1]);

        if (i + arr[i].first - 1 > N) continue;

        dp[i + arr[i].first] = max(dp[i + arr[i].first], dp[i] + arr[i].second);
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';

    cout << max(dp[N], dp[N + 1]);
}