#include <bits/stdc++.h>
using namespace std;

bool vis[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, K;
    cin >> M >> N >> K;

    int cnt = 0;
    int sx, sy, ex, ey;
    queue<pair<int, int>> Q;
    priority_queue<int, vector<int>, greater<int>> PQ;
    while (K--) {
        cin >> sx >> sy >> ex >> ey;

        for (int i = sy; i < ey; i++) {
            for (int j = sx; j < ex; j++) {
                vis[i][j] = true;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;
            cnt++;

            Q.push({i, j});
            vis[i][j] = true;
            int area = 0;
            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();
                area++;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny]) continue;

                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
            PQ.push(area);
        }
    }

    cout << cnt << '\n';
    while (!PQ.empty()) {
        cout << PQ.top() << " ";
        PQ.pop();
    }
}