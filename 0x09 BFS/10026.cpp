#include <bits/stdc++.h>
using namespace std;

bool vis[102][102];
char board[102][102];
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j) {
    queue<pair<int, int>> Q;
    Q.push({i, j});
    vis[i][j] = true;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vis[nx][ny] || board[i][j] != board[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int count_area() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;
            cnt++;
            bfs(i, j);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    int ans1 = count_area();

    for (int i = 0; i < N; i++) {
        fill(vis[i], vis[i] + N, false);
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'G') board[i][j] = 'R';
        }
    }

    int ans2 = count_area();

    cout << ans1 << " " << ans2;
}