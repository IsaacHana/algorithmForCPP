#include <bits/stdc++.h>
using namespace std;

int N, M;
int dist[301][301];
bool vis[301][301];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool splits() {
    int area_cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] <= 0 || vis[i][j]) continue;
            area_cnt++;
            if (area_cnt > 1) return true;

            queue<pair<int, int>> Q;
            Q.push({i, j});
            vis[i][j] = true;

            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (dist[nx][ny] <= 0) continue;
                    if (vis[nx][ny]) continue;

                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        fill(vis[i], vis[i] + M, false);
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    queue<tuple<int, int, int>> Q;
    queue<tuple<int, int, int>> Q2;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int val;
            cin >> val;
            dist[i][j] = val;
            if (val) {
                Q.push({i, j, val});
            }
        }
    }
    int ans = 0;
    while (!Q.empty()) {
        ++ans;
        int qsize = Q.size();
        for (int i = 0; i < qsize; i++) {
            int x, y, cnt;
            tie(x, y, cnt) = Q.front();
            Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (dist[nx][ny] > 0) continue;

                cnt--;
            }

            Q2.push({x, y, cnt});
        }

        while (!Q2.empty()) {
            int x, y, cnt;
            tie(x, y, cnt) = Q2.front();
            Q2.pop();

            dist[x][y] = cnt;
            if (cnt <= 0) continue;
            Q.push({x, y, cnt});
        }

        if (splits()) {
            cout << ans;
            return 0;
        }
    }

    cout << 0;
}