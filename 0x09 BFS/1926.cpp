#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool board[501][501];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, cnt = 0, mx = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!board[i][j]) continue;
            cnt++;

            queue<pair<int, int>> Q;
            Q.push({i, j});
            board[i][j] = false;
            int tmp = 0;

            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (!board[nx][ny]) continue;

                    board[nx][ny] = false;
                    Q.push({nx, ny});
                }
                tmp++;
            }

            mx = max(mx, tmp);
        }
    }

    cout << cnt << '\n';
    cout << mx << '\n';
}