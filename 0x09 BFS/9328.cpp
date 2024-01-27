#include <bits/stdc++.h>
using namespace std;

char board[102][102];
bool vis[102][102];
bool hasKey[26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 0; i <= N + 1; i++) {
            fill(board[i], board[i] + M + 2, '.');
            fill(vis[i], vis[i] + M + 2, false);
        }
        fill(hasKey, hasKey + 26, false);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> board[i][j];
            }
        }

        string keys;
        cin >> keys;
        if (keys != "0") {
            for (char key : keys) {
                hasKey[key - 'a'] = true;
            }
        }

        queue<pair<int, int>> Q;
        Q.push({0, 0});
        vis[0][0] = true;
        queue<pair<int, int>> visDoor[26];

        int ans = 0;
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx > N + 1 || ny < 0 || ny > M + 1) continue;
                if (board[nx][ny] == '*') continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = true;

                if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z') {
                    int door = board[nx][ny] - 'A';
                    // cout << "door : " << door << '\n';

                    if (!hasKey[door]) {
                        visDoor[door].push({nx, ny});
                        continue;
                    }
                } else if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z') {
                    int key = board[nx][ny] - 'a';
                    // cout << "key : " << key << '\n';
                    hasKey[key] = true;

                    while (!visDoor[key].empty()) {
                        auto visited = visDoor[key].front();
                        visDoor[key].pop();
                        Q.push({visited.first, visited.second});
                    }
                } else if (board[nx][ny] == '$') {
                    ans++;
                }

                Q.push({nx, ny});
            }
        }

        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= M; j++) {
        //         cout << board[i][j];
        //     }
        //     cout << '\n';
        // }
        // for (int i = 0; i <= N + 1; i++) {
        //     for (int j = 0; j <= M + 1; j++) {
        //         cout << vis[i][j];
        //     }
        //     cout << '\n';
        // }
        cout << ans << '\n';
    }
}