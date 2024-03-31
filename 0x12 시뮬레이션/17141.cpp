#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[52][52];
vector<pair<int, int>> vec;
vector<pair<int, int>> vir;
int vis[52][52];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int MAX = 987654321;
int ans = MAX;

void bfs() {
    int dist[52][52] = {};
    queue<pair<int, int>> q;
    for (auto v : vir) {
        q.push(v);
    }

    int mx = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (board[nx][ny] == 1) continue;
            if (dist[nx][ny]) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            if (mx >= ans) return;
            mx = max(mx, dist[nx][ny]);
            q.push({nx, ny});
        }
    }

    bool flag = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j] == 0 && dist[i][j] == 0) flag = false;
        }
    }

    if (flag) ans = min(ans, mx);

    // for (int i = 0; i <= N + 1; i++) {
    //     for (int j = 0; j <= N + 1; j++) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}

void dfs(int depth) {
    if (depth == M) {
        for (auto v : vir) {
            cout << v.first << " " << v.second << ", ";
        }
        cout << '\n';

        // bfs();
        return;
    }

    for (auto v : vec) {
        if (vis[v.first][v.second]) continue;

        // if (vir[depth].first != 0 && vir[depth].first >= v.first && vir[depth].second >= v.second) continue;
        vir.push_back(v);
        vis[v.first][v.second] = true;
        dfs(depth + 1);
        vis[v.first][v.second] = false;
        vir.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i <= N + 1; i++) {
        fill(board[i], board[i] + N + 2, 1);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) vec.push_back({i, j});
        }
    }

    dfs(0);

    if (ans == MAX)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}