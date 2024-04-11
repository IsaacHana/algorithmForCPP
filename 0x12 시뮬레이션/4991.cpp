#include <bits/stdc++.h>
using namespace std;

const int MAX = (~0u >> 2);

int ans = MAX;

int w, h;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char board[22][22];

vector<pair<int, int>> dirty_spaces;
vector<tuple<int, int, int>> other_spaces[22][22];
bool vis[22][22];

void bfs(int x, int y) {
    int dist[22][22] = {};

    for (int i = 0; i < 22; i++) {
        fill(dist[i], dist[i] + 22, -1);
    }

    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;

    bool flag = false;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (dist[nx][ny] >= 0) continue;
            if (board[nx][ny] == 'x') continue;
            if (board[nx][ny] == '*') {
                other_spaces[x][y].push_back({nx, ny, dist[cur.first][cur.second] + 1});
            }

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            q.push({nx, ny});
        }
    }

    // for (auto cs : other_spaces[x][y]) {
    //     int nx, ny, dist;
    //     tie(nx, ny, dist) = cs;
    //     cout << x << " " << y << " 의 와 다른 더러운 노드들의 관계 " << nx << " " << ny << " 거리 : " << dist << '\n';
    // }
}

void dfs(int depth, int x, int y, int total) {
    if (ans <= total) return;

    if (depth == dirty_spaces.size()) {
        ans = min(ans, total);
        return;
    }

    for (auto c : other_spaces[x][y]) {
        int nx, ny, dist;
        tie(nx, ny, dist) = c;
        if (vis[nx][ny]) continue;
        vis[nx][ny] = true;
        dfs(depth + 1, nx, ny, total + dist);
        vis[nx][ny] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        ans = MAX;

        for (int i = 0; i < 22; i++) {
            fill(board[i], board[i] + 22, '.');
        }

        cin >> w >> h;

        if (w == 0 && h == 0) break;

        int sx, sy;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> board[i][j];

                if (board[i][j] == '*') {
                    dirty_spaces.push_back({i, j});
                }
                if (board[i][j] == 'o') {
                    sx = i;
                    sy = j;
                }
            }
        }
        // 시작점에서 가까운 더러운 칸 구하기
        bfs(sx, sy);
        // 각 더러운 칸에서 가까운 다른 더러운 칸 구하기
        for (auto ds : dirty_spaces) {
            bfs(ds.first, ds.second);
        }

        dfs(0, sx, sy, 0);

        if (ans == MAX)
            cout << -1 << '\n';
        else
            cout << ans << '\n';

        // 초기화
        dirty_spaces.clear();

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                other_spaces[i][j].clear();
                vis[i][j] = false;
            }
        }
    }
}