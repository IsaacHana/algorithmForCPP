#include <bits/stdc++.h>
using namespace std;

const int INITIAL_SIZE = 2;

int N;

int board[22][22];
bool vis[22][22];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fish;
// x, y, size, eat
queue<pair<int, int>> q;
int shark_size = INITIAL_SIZE;
int eat = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int ans = 0;

void bfs(int sx, int sy) {
    q.push({sx, sy});

    for (int i = 0; i < N; i++) {
        fill(vis[i], vis[i] + N, false);
    }

    int cnt = 0;
    while (!q.empty() && fish.empty()) {
        int qSize = q.size();
        cnt++;

        for (int i = 0; i < qSize; i++) {
            int x, y;
            tie(x, y) = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (vis[nx][ny]) continue;
                if (board[nx][ny] > shark_size) continue;

                if (board[nx][ny] != 0 && board[nx][ny] < shark_size) {
                    fish.push({nx, ny});
                }

                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    while (!q.empty()) {
        q.pop();
    }

    if (fish.empty()) return;

    ans += cnt;
    int x = fish.top().first;
    int y = fish.top().second;
    // cout << "going To : " << x << " " << y << '\n';
    // eat
    board[x][y] = 0;
    while (!fish.empty()) {
        fish.pop();
    }
    eat += 1;

    // size up
    if (shark_size == eat) {
        shark_size += 1;
        eat = 0;
    }

    // cout << "time : " << ans << '\n';

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    bfs(x, y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int sx, sy;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                board[i][j] = 0;
                sx = i;
                sy = j;
            }
        }
    }

    bfs(sx, sy);

    cout << ans << '\n';
}