#include <bits/stdc++.h>
using namespace std;

int N;

int cnt = 0;
int vis_row[15];
int vis_up_cross[29];  // 2 * N - 1;
int vis_down_cross[29];

void dfs(int depth) {
    // base
    if (depth == N) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (vis_row[i]) continue;
        if (vis_up_cross[i + depth]) continue;
        if (vis_down_cross[depth - i + N - 1]) continue;

        vis_row[i] = true;
        vis_up_cross[i + depth] = true;
        vis_down_cross[depth - i + N - 1] = true;

        dfs(depth + 1);

        vis_row[i] = false;
        vis_up_cross[i + depth] = false;
        vis_down_cross[depth - i + N - 1] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    dfs(0);
    cout << cnt;
}