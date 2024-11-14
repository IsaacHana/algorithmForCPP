#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, vip;
    cin >> N >> M;

    vector<int> vec;
    vec.push_back(0);
    int dp[42];

    while (M--) {
        cin >> vip;
        vec.push_back(vip);
    }

    vec.push_back(N + 1);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];

    int ans = 1;
    for (int i = 1; i < vec.size(); i++) {
        ans *= dp[vec[i] - vec[i - 1] - 1];
    }

    cout << ans << '\n';
}