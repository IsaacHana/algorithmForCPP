#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, K;
    cin >> M >> N >> K;
    int board[M][N] = {};

    while (K--) {
        int SX, SY, EX, EY;
        cin >> SX >> SY >> EX >> EY;

        for (int i = SY; i < EY; i++) {
            for (int j = SX; j < EX; j++) {
                board[i][j] = 1;
            }
        }
    }

    priority_queue<int, vector<int>, greater<int>> area_Q;

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) continue;
            cnt++;

            queue<pair<int, int>> Q;
            Q.push({i, j});
            board[i][j] = 1;

            int area = 0;
            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                    if (board[nx][ny] == 1) continue;

                    board[nx][ny] = 1;
                    Q.push({nx, ny});
                }
                area++;
            }
            area_Q.push(area);
        }
    }

    cout << cnt << '\n';
    while (!area_Q.empty()) {
        cout << area_Q.top() << " ";
        area_Q.pop();
    }
}
