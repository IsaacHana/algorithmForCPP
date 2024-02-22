#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1 -> 1
    // 2 -> 2
    // 3 -> (1 + 2)-> 3
    // 4 -> ((1 + 2) + 2) -> 5
    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10'007;
    }
    cout << dp[N] << '\n';
}