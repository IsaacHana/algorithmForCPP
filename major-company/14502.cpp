#include <bits/stdc++.h>
using namespace std;

const int EMPTY = 0;
const int WALL = 1;
const int VIRUS = 2;
const int LIMIT_WALL_CNT = 3;
int N, M;
int board[10][10];
vector<pair<int, int>> virus;
int total;
int wall_cnt = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 0;

int count_safe_area(bool vis[10][10]) {
    int virus_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vis[i][j]) virus_cnt++;
        }
    }

    return total - wall_cnt - virus_cnt;
}
int bfs() {
    queue<pair<int, int>> q;
    bool vis[10][10] = {};
    for (auto v : virus) {
        q.push(v);
        vis[v.first][v.second] = true;
    }

    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny]) continue;
            if (board[nx][ny] == WALL) continue;

            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return count_safe_area(vis);
}

void dfs(int depth, int start) {
    if (depth == LIMIT_WALL_CNT) {
        ans = max(ans, bfs());
        return;
    }

    for (int i = start; i < N * M; i++) {
        int x = i / M;
        int y = i % M;

        if (board[x][y]) continue;
        board[x][y] = WALL;
        dfs(depth + 1, i + 1);
        board[x][y] = EMPTY;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    total = N * M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == VIRUS) virus.push_back({i, j});
            if (board[i][j] == WALL) wall_cnt++;
        }
    }
    wall_cnt += LIMIT_WALL_CNT;

    dfs(0, 0);

    cout << ans;
}