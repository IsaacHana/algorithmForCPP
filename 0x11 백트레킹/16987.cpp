#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> egg[10];
int arr[10];
int ans = 0;
int cnt = 0;
void dfs(int depth) {
    if (depth == N) {
        ans = max(ans, cnt);
        return;
    }

    if (egg[depth].first <= 0 || cnt == N - 1) {
        dfs(depth + 1);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (depth == i) continue;
        if (egg[i].first <= 0) continue;

        egg[depth].first -= egg[i].second;
        egg[i].first -= egg[depth].second;
        if (egg[depth].first <= 0) cnt++;
        if (egg[i].first <= 0) cnt++;
        dfs(depth + 1);
        if (egg[depth].first <= 0) cnt--;
        if (egg[i].first <= 0) cnt--;
        egg[depth].first += egg[i].second;
        egg[i].first += egg[depth].second;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int S, W;
    for (int i = 0; i < N; i++) {
        cin >> S >> W;
        egg[i] = {S, W};
    }

    dfs(0);

    cout << ans << '\n';
}