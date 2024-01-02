#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, M, K;
        cin >> M >> N >> K;
        int dist[N][M] = {};
        int ans = 0;

        while (K--) {
            int X, Y;
            cin >> X >> Y;
            dist[Y][X] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (dist[i][j] == 0) continue;
                ans++;

                queue<pair<int, int>> Q;
                Q.push({i, j});
                dist[i][j] = 1;
                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= M || dist[nx][ny] == 0) continue;
                        dist[nx][ny] = 0;
                        Q.push({nx, ny});
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}