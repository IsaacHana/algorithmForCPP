#include <bits/stdc++.h>
using namespace std;

int dist[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, val, total = 0;
    cin >> N >> M;
    queue<pair<int, int>> Q;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> val;
            dist[i][j] = val;
            if (val == -1)
                continue;
            else if (val == 1)
                Q.push({i, j});
            total++;
        }
    }
    int cnt = -1;
    while (!Q.empty()) {
        int qsize = Q.size();
        for (int s = 0; s < qsize; s++) {
            auto cur = Q.front();
            Q.pop();
            total--;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                if (dist[nx][ny]) continue;

                dist[nx][ny] = 1;
                Q.push({nx, ny});
            }
        }
        cnt++;
    }

    if (total)
        cout << -1 << '\n';
    else
        cout << cnt << '\n';
}