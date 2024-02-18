#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int W = 5;
const int H = 5;
const int M = 7;
const int MX = H * W;

string board[W];
bool mask[MX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 0;

bool bfs() {
    int s_cnt = 0;

    queue<pair<int, int>> q;
    bool vis[H][W] = {};
    int end_x;
    int end_y;
    for (int i = 0; i < MX; i++) {
        if (mask[i]) {
            int x = i / W;
            int y = i % W;

            end_x = x;
            end_y = y;
            vis[x][y] = true;

            if (board[x][y] == 'S') s_cnt++;
        }
    }

    if (s_cnt < 4) return false;

    int adj_cnt = 0;
    bool vis1[H][W] = {};

    q.push({end_x, end_y});
    vis1[end_x][end_y] = true;

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        adj_cnt++;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (!vis[nx][ny]) continue;
            if (vis1[nx][ny]) continue;

            vis1[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    if (adj_cnt != M) return false;

    return true;
}

void dfs(int depth, int start) {
    if (depth == M) {
        if (bfs()) {
            ans++;
        }
        return;
    }

    for (int i = start; i < MX; i++) {
        if (mask[i]) continue;
        mask[i] = true;
        dfs(depth + 1, i + 1);
        mask[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < H; i++) {
        cin >> board[i];
    }
    dfs(0, 0);
    cout << ans << '\n';
}