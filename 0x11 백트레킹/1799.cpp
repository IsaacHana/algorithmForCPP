#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> board[2][20];
bool vis[2][20];
int ans[2];
void backtracking(int depth, int cnt, int color) {
    // base case
    if (depth == 2 * N - 1) {
        ans[color] = max(ans[color], cnt);
        return;
    }

    for (auto v : board[color][depth]) {
        int x, y;
        tie(x, y) = v;
        if (vis[color][x + y]) continue;
        vis[color][x + y] = true;
        backtracking(depth + 1, cnt + 1, color);
        vis[color][x + y] = false;
    }
    backtracking(depth + 1, cnt, color);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int val;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> val;
            if (val) board[(i + j) % 2][N + i - j - 1].push_back({i, j});
        }
    }

    backtracking(0, 0, 0);
    backtracking(0, 0, 1);
    cout << ans[0] + ans[1] << '\n';
}