#include <bits/stdc++.h>
using namespace std;

int dist[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    string str;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        for (int j = 1; j <= M; j++) {
            int val = str[j - 1] - '0';
            if (val) {
                dist[i][j] = -1;
            }
        }
    }
    queue<pair<int, int>> Q;
    Q.push({1, 1});
    dist[1][1] = 0;
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }
    cout << dist[N][M] + 1 << '\n';
}