#include <bits/stdc++.h>
using namespace std;

const int N = 12;
const int M = 6;

char board[N + 1][M];
bool vis[N + 1][M];
int ans = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<queue<pair<int, int>>> explosion_queue;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> gravity_queue;

void explode() {
    ans++;
    while (!explosion_queue.empty()) {
        auto empty_queue = explosion_queue.front();
        explosion_queue.pop();
        while (!empty_queue.empty()) {
            int x, y;
            tie(x, y) = empty_queue.front();
            empty_queue.pop();

            gravity_queue.push({x, y});

            board[x][y] = '.';
        }
    }
}

void gravity() {
    while (!gravity_queue.empty()) {
        int x, y;
        tie(x, y) = gravity_queue.top();
        gravity_queue.pop();

        for (int i = x - 1; i >= 0; i--) {
            board[i + 1][y] = board[i][y];
        }
    }
}

void bfs(int x, int y) {
    if (board[x][y] == '.') return;

    char ch = board[x][y];

    queue<pair<int, int>> q;
    queue<pair<int, int>> empty_queue;
    q.push({x, y});
    empty_queue.push({x, y});
    vis[x][y] = true;
    while (!q.empty()) {
        int cx, cy;
        tie(cx, cy) = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx < 1 || nx > N || ny < 0 || ny >= M) continue;
            if (vis[nx][ny]) continue;
            if (board[nx][ny] != ch) continue;

            vis[nx][ny] = true;
            q.push({nx, ny});
            empty_queue.push({nx, ny});
        }
    }

    if (empty_queue.size() >= 4) {
        explosion_queue.push(empty_queue);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int j = 0; j < M; j++) {
        board[0][j] = '.';
    }

    while (true) {
        for (int i = N; i > 0; i--) {
            fill(vis[i], vis[i] + M, false);
        }
        for (int i = N; i > 0; i--) {
            for (int j = 0; j < M; j++) {
                bfs(i, j);
            }
        }
        if (explosion_queue.empty()) {
            break;
        }
        explode();
        gravity();

        cout << "=================\n";
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    cout << ans << '\n';
}