#include <iostream>
using namespace std;

int dp[1'000'001];
int prv[1'000'001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        prv[i] = i - 1;
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            prv[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            prv[i] = i / 3;
        }
    }

    cout << dp[N] << '\n';

    // for (int i = 1; i <= N; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= N; i++) {
    //     cout << i << " : " << prv[i] << '\n';
    // }
    int cur = N;
    while (cur != 0) {
        cout << cur << ' ';
        cur = prv[cur];
    }
}