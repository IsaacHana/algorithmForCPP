#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int board[N][N];
    int mx_cnt = 0;
    int mx_h = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            cin >> val;
            mx_h = max(mx_h, val);
            board[i][j] = val;
        }
    }

    int dist[N][N];

    while (mx_h--) {
        for (int i = 0; i < N; i++) {
            fill(dist[i], dist[i] + N, -1);
            for (int j = 0; j < N; j++) {
                if (mx_h >= board[i][j]) {
                    dist[i][j] = 0;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] == 0) continue;
                cnt++;

                queue<pair<int, int>> Q;
                Q.push({i, j});
                dist[i][j] = 0;

                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (dist[nx][ny] == 0) continue;

                        dist[nx][ny] = 0;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        mx_cnt = max(mx_cnt, cnt);
    }
    cout << mx_cnt;
}