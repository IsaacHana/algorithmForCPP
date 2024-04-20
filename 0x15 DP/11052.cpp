#include <bits/stdc++.h>
using namespace std;

int dp[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> dp[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i - j] + dp[j], dp[i]);
        }
    }
    cout << dp[N] << '\n';
}