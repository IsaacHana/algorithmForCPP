#include <bits/stdc++.h>
using namespace std;

int N;
int S[9], W[9];
bool vis[9];
int ans = 0;
int cnt = 0;

void backTracking(int depth) {
    // base case
    if (depth == N) {
        ans = max(ans, cnt);
        return;
    }

    if (S[depth] <= 0 || cnt == N - 1) {
        backTracking(depth + 1);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (i == depth || S[i] <= 0) continue;
        S[depth] -= W[i];
        S[i] -= W[depth];
        if (S[depth] <= 0) cnt++;
        if (S[i] <= 0) cnt++;
        backTracking(depth + 1);
        if (S[depth] <= 0) cnt--;
        if (S[i] <= 0) cnt--;
        S[depth] += W[i];
        S[i] += W[depth];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> W[i];
    }

    backTracking(0);

    cout << ans;
}