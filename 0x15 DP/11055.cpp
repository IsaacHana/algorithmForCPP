#include <bits/stdc++.h>
using namespace std;

int A[1002];
int dp[1002];

int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
        dp[i] = A[i];
    }

    for (int i = 1; i < N; i++)
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + A[i]);
            }
        }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        // cout << dp[i] << ' ';
        ans = max(ans, dp[i]);
    }
    // cout << '\n';

    cout << ans << '\n';
}