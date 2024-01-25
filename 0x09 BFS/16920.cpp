#include <bits/stdc++.h>
using namespace std;

int board[1001][1001];
int S[10];
int cnt[10];
queue<pair<int, int>> adj[10];

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

    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            if (c == '#')
                board[i][j] = -1;
            else if (c == '.')
                board[i][j] = 0;
            else {
                int val = c - '0';
                board[i][j] = val;
                adj[val].push({i, j});
                cnt[val]++;
            }
        }
    }

    while (true) {
        bool escape = true;
        for (int i = 1; i <= P; i++) {
            for (int j = 0; j < S[i]; j++) {
                int qsize = adj[i].size();
                if (qsize <= 0) break;

                for (int k = 0; k < qsize; k++) {
                    int x, y;
                    tie(x, y) = adj[i].front();
                    adj[i].pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if (board[nx][ny]) continue;
                        escape = false;
                        cnt[i]++;
                        board[nx][ny] = i;
                        adj[i].push({nx, ny});
                    }
                }
            }
        }
        if (escape) break;
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = 1; i <= P; i++) {
        cout << cnt[i] << " ";
    }
}