#include <bits/stdc++.h>
using namespace std;

int DP[13];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    cin >> T;

    // tabulation
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 4; i < 11; i++) {
        DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
    }

    while (T--) {
        cin >> n;

        cout << DP[n] << '\n';
    }
}