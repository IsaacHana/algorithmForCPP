#include <bits/stdc++.h>
using namespace std;

string board[5];
bool mask[25];
int ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    queue<pair<int, int>> Q;
    int adj_cnt = 0;
    int s_cnt = 0;
    bool vis[5][5] = {};

    for (int i = 0; i < 25; i++) {
        if (mask[i]) {
            int x = i / 5;
            int y = i % 5;

            Q.push({x, y});
            vis[x][y] = true;
            break;
        }
    }

    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front();
        Q.pop();

        adj_cnt++;
        if (board[x][y] == 'S') s_cnt++;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (!mask[nx * 5 + ny]) continue;
            if (vis[nx][ny]) continue;

            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }

    if (adj_cnt == 7 && s_cnt >= 4) {
        ans++;
    }
}
void backTracking(int depth, int start) {
    // basc case
    if (depth == 7) {
        bfs();
        return;
    }

    for (int i = start; i < 25; i++) {
        if (mask[i]) continue;
        mask[i] = true;
        backTracking(depth + 1, i + 1);
        mask[i] = false;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) cin >> board[i];
    // mask[5] = true;
    // mask[6] = true;
    // mask[7] = true;
    // mask[8] = true;
    // mask[9] = true;
    // mask[14] = true;
    // mask[19] = true;
    // bfs();
    backTracking(0, 0);

    cout << ans;
}