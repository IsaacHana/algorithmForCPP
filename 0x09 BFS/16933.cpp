#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

string board[1001];
int dist[11][1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    queue<tuple<int, int, int, int, int>> Q;
    Q.push({1, K, 0, 0, 1});
    dist[K][0][0] = 1;

    while (!Q.empty()) {
        int qsize = Q.size();
        int isBright, k, x, y, stay;
        tie(isBright, k, x, y, stay) = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (board[nx][ny] == '1') {                                   // 벽
                if (!isBright || k < 1 || dist[k - 1][nx][ny]) continue;  // 밤이거나 횟수 전부 사용했거나 방분했다면 넘겨

                dist[k - 1][nx][ny] = dist[k][x][y] + 1;
                Q.push({!isBright, k - 1, nx, ny, 1});
            } else {  // 벽X
                if (dist[k][nx][ny]) continue;
                dist[k][nx][ny] = dist[k][x][y] + 1;
                Q.push({!isBright, k, nx, ny, 1});
            }
        }

        if (stay > 0) {
            dist[k][x][y] = dist[k][x][y] + 1;
            Q.push({!isBright, k, x, y, stay - 1});
        }
    }

    int ans = INF;

    for (int j = 0; j <= K; j++) {
        if (dist[j][N - 1][M - 1]) ans = min(ans, dist[j][N - 1][M - 1]);
    }

    if (ans == INF)
        cout << -1;
    else
        cout << ans - 1;
}