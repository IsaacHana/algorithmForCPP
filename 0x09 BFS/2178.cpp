#include <bits/stdc++.h>
using namespace std;

int maze[101][101];
bool vis[101][101];
int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void maze_init() {
    for (int i = 1; i <= N; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= M; j++) maze[i][j] = str[j - 1] - '0';
    }
}

int bfs() {
    int ans = 1;
    queue<pair<int, int>> Q;
    Q.push({1, 1});
    vis[1][1] = true;

    while (!Q.empty()) {
        int qsize = Q.size();
        for (int i = 0; i < qsize; i++) {
            pair<int, int> cur = Q.front();
            Q.pop();
            if (cur.first == N && cur.second == M) return ans;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx <= 0 || nx > N || ny <= 0 || ny > M || maze[nx][ny] == 0 || vis[nx][ny]) continue;

                vis[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
        ans++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    maze_init();
    cout << bfs();
}