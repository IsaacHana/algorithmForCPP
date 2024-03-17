#include <bits/stdc++.h>
using namespace std;

long long dp[101][10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    // 1 : 1 2 3 4 5 6 7 8 9
    // 2 : 12 10, 23 21, 34 32, 45 43, 56 54, 67 65, 78 76, 89 87, (90X) 98
    // 3 : 123 121, 101 (109X), 234 232, 212 210 <-미래의 -1 계기, 345 343, 323 321, ... , (890X) 898 ,989 987
    // 4 : (2109 X) (7890X) (9890X)

    for (int i = 1; i <= 9; ++i) dp[1][i] += 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j != 0) dp[i][j] += dp[i - 1][j - 1];
            if (j != 9) dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= 1'000'000'000;
        }
    }

    long long ans = 0;

    for (int i = 0; i <= 9; i++) {
        ans += dp[N][i];
    }
    ans %= 1'000'000'000;
    cout << ans << '\n';
}