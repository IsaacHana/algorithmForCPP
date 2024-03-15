#include <bits/stdc++.h>
using namespace std;
long long dp[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, val, mx = 0;
    cin >> T;
    vector<int> nums;
    while (T--) {
        cin >> val;
        mx = max(mx, val);
        nums.push_back(val);
    }

    // tabulation
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= mx; i++) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    for (auto num : nums) {
        cout << dp[num] << '\n';
    }
}