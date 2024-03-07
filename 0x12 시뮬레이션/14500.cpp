#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[502][502];
bool vis[502][502];

vector<pair<int, int>> tetro;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 0;
int mx = 0;

void dfs(int depth, int total) {
    if (total + (4 - depth) * mx <= ans) {
        return;
    }

    if (depth == 4) {
        ans = max(ans, total);
        return;
    }

    for (auto tet : tetro) {
        for (int dir = 0; dir < 4; dir++) {
            int nx = tet.first + dx[dir];
            int ny = tet.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny]) continue;
            tetro.push_back({nx, ny});
            vis[nx][ny] = true;
            dfs(depth + 1, total + board[nx][ny]);
            vis[nx][ny] = false;
            tetro.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            mx = max(mx, board[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vis[i][j] = true;
            tetro.push_back({i, j});
            dfs(1, board[i][j]);
            tetro.pop_back();
        }
    }

    cout << ans << '\n';
}