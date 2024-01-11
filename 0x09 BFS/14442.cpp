#include <bits/stdc++.h>
using namespace std;

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

    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    dist[0][0][0] = 1;

    while (!Q.empty()) {
        int k, x, y;
        tie(k, x, y) = Q.front();
        Q.pop();

        if (x == N - 1 && y == M - 1) {
            cout << dist[k][x][y];
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            int nk = k;
            if (board[nx][ny] == '1') nk++;
            if (nk > K || dist[nk][nx][ny] > 0) continue;
            dist[nk][nx][ny] = dist[k][x][y] + 1;
            Q.push({nk, nx, ny});
        }
    }
    cout << -1;
}