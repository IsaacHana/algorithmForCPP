#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int S[11];
int cnt[11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, P;
    cin >> N >> M >> P;

    for (int i = 1; i <= P; i++) {
        cin >> S[i];
    }
    queue<tuple<int, int, int>> Q[10];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char val;
            cin >> val;

            if (val == '.')
                board[i][j] = 0;
            else if (val == '#')
                board[i][j] = 1;
            else {
                board[i][j] = 1;
                Q[val - '0'].push({i, j, 0});
                cnt[val - '0']++;
            }
        }
    }

    while (true) {
        bool isExtend = false;

        for (int i = 1; i <= P; i++) {
            queue<tuple<int, int, int>> NQ;
            while (!Q[i].empty()) {
                int x, y, s;
                tie(x, y, s) = Q[i].front();
                Q[i].pop();

                if (s >= S[i]) {
                    NQ.push({x, y, 0});
                    continue;
                }

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                    if (board[nx][ny]) continue;
                    board[nx][ny] = 1;
                    Q[i].push({nx, ny, s + 1});
                    cnt[i]++;
                    isExtend = true;
                }
            }
            Q[i] = NQ;
        }
        if (!isExtend) break;
    }

    for (int i = 1; i <= P; i++) {
        cout << cnt[i] << " ";
    }
}