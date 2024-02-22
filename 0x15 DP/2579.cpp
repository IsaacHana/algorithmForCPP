#include <bits/stdc++.h>
using namespace std;

int stairs[302];
int DP[302];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> stairs[i];
    }

    DP[0] = stairs[0];
    DP[1] = max(stairs[0] + stairs[1], stairs[1]);
    DP[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    for (int i = 3; i < N; i++) {
        DP[i] = max(DP[i - 2] + stairs[i], DP[i - 3] + stairs[i - 1] + stairs[i]);
    }

    cout << DP[N - 1] << '\n';
}