#include <bits/stdc++.h>
using namespace std;

int nums[100'010];
int dp[100'010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 100'000'000

    int n;
    cin >> n;
    int ans = -(~0U >> 2);

    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = max(0, dp[i - 1]) + nums[i];
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
}