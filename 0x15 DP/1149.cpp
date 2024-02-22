#include <bits/stdc++.h>
using namespace std;

int house[3][1001];
int dp[3][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> house[j][i];
        }
    }

    dp[0][1] = house[0][1];
    dp[1][1] = house[1][1];
    dp[2][1] = house[2][1];

    for (int i = 1; i <= N; i++) {
        dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + house[0][i];
        dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + house[1][i];
        dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + house[2][i];
    }

    cout << min({dp[0][N], dp[1][N], dp[2][N]}) << '\n';
}