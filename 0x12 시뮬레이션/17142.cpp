#include <bits/stdc++.h>
using namespace std;

int board[52][52];
vector<pair<int, int>> vec;
vector<pair<int, int>> vir;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;

const int MAX = (~0U >> 2);
int ans = MAX;

int emptyCnt = 0;

void bfs() {
    int dist[52][52];

    for (int i = 0; i < N; i++) fill(dist[i], dist[i] + N, -1);

    queue<pair<int, int>> q;

    for (auto v : vir) {
        q.push(v);
        dist[v.first][v.second] = 0;
    }

    int times = 0;
    int cnt = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (board[nx][ny] == 1) continue;
            if (dist[nx][ny] >= 0) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;

            q.push({nx, ny});

            if (board[nx][ny] != 2) {
                times = dist[nx][ny];
                cnt++;
            }
        }
    }

    if (emptyCnt == cnt) ans = min(ans, times);
}

void dfs(int depth, int start) {
    if (depth == M) {
        // for (auto v : vir) {
        //     cout << v.first << " " << v.second << '\n';
        // }
        // cout << '\n';
        bfs();
        return;
    }

    for (int i = start; i < vec.size(); i++) {
        auto v = vec[i];

        vir.push_back(v);
        dfs(depth + 1, i + 1);
        vir.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) emptyCnt++;
            if (board[i][j] == 2) vec.push_back({i, j});
        }
    }

    dfs(0, 0);

    if (ans == MAX)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}
