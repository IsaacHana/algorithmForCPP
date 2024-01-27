#include <bits/stdc++.h>
using namespace std;

int R, C;

queue<pair<int, int>> bird;
queue<pair<int, int>> bird_cache;
queue<pair<int, int>> water;
queue<pair<int, int>> water_cache;

char board[1501][1501];
bool vis_bird[1501][1501];
bool vis_water[1501][1501];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isConnect() {
    while (!bird.empty()) {
        auto cur = bird.front();
        bird.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (vis_bird[nx][ny]) continue;
            vis_bird[nx][ny] = true;
            if (board[nx][ny] == 'L') {
                return true;
            } else if (board[nx][ny] == 'X') {
                bird_cache.push({nx, ny});
            } else {
                bird.push({nx, ny});
            }
        }
    }

    while (!bird_cache.empty()) {
        auto cur = bird_cache.front();
        bird_cache.pop();

        bird.push({cur.first, cur.second});
    }

    return false;
}

void melting() {
    while (!water.empty()) {
        auto cur = water.front();
        water.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (vis_water[nx][ny]) continue;

            if (board[nx][ny] == 'X') {
                water_cache.push({nx, ny});
            }
            vis_water[nx][ny] = true;
        }
    }

    while (!water_cache.empty()) {
        auto cur = water_cache.front();
        water_cache.pop();
        board[cur.first][cur.second] = '.';
        water.push({cur.first, cur.second});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;

    char c;
    pair<int, int> bird_start;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> c;
            board[i][j] = c;
            if (c == 'L') {
                bird_start = {i, j};
            }
            if (c != 'X') {
                water.push({i, j});
                vis_water[i][j] = true;
            }
        }
    }

    bird.push(bird_start);
    board[bird_start.first][bird_start.second] = '.';
    vis_bird[bird_start.first][bird_start.second] = true;

    int ans = 0;
    while (!isConnect()) {
        melting();
        ans++;
    }
    cout << ans;
}