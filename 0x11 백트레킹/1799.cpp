#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> board[2][20];
int N;
int vis[20];
int ans[2];

void dfs(int depth, int cnt, int color) {
    // 가지 치기
    if (ans[color] >= cnt + N - 1) {
        return;
    }

    // base case
    if (depth == 2 * N - 1) {
        ans[color] = max(ans[color], cnt);
        return;
    }

    for (auto cur : board[color][depth]) {
        int x, y;
        tie(x, y) = cur;
        if (vis[x + y]) continue;
        vis[x + y] = true;
        dfs(depth + 1, cnt + 1, color);
        vis[x + y] = false;
    }

    dfs(depth + 1, cnt, color);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int val;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> val;
            if (val) board[(i + j) % 2][N - 1 + i - j].push_back({i, j});
        }
    }

    dfs(0, 0, 0);
    dfs(0, 0, 1);

    cout << ans[0] + ans[1] << '\n';
}
