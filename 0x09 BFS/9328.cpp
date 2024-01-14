#include <bits/stdc++.h>
using namespace std;

int T, h, w;
char board[102][102];
bool vis[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> h >> w;
        // .......
        // .*****.
        // .*.$.*.
        // .*****.
        // .......
        for (int i = 0; i <= h + 1; i++) {
            fill(board[i], board[i] + w + 2, '.');
            fill(vis[i], vis[i] + w + 2, false);
        }

        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                cin >> board[i][j];
            }
        }

        bool key[26] = {};
        string keyStr;
        cin >> keyStr;
        for (char c : keyStr) {
            key[c - 'a'] = true;
        }

        queue<pair<int, int>> Q;
        queue<pair<int, int>> door[26];
        int ans = 0;
        Q.push({0, 0});
        vis[0][0] = true;
        while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1) continue;
                if (board[nx][ny] == '*' || vis[nx][ny]) continue;
                vis[nx][ny] = true;

                if (board[nx][ny] == '$') {  // 문서
                    ans++;
                } else if (board[nx][ny] >= 'A' && board[nx][ny] <= 'Z') {  // 문
                    int idx = tolower(board[nx][ny]) - 'a';
                    // if (key[idx] == true) cout << board[nx][ny] << " " << nx << "," << ny << '\n';
                    if (!key[idx]) {
                        door[idx].push({nx, ny});
                        continue;
                    }
                } else if (board[nx][ny] >= 'a' && board[nx][ny] <= 'z') {  // 키
                    int idx = board[nx][ny] - 'a';
                    key[idx] = true;

                    while (!door[idx].empty()) {
                        auto nd = door[idx].front();
                        door[idx].pop();
                        // cout << nd.first << " " << nd.second << '\n';
                        Q.push({nd.first, nd.second});
                    }
                }
                Q.push({nx, ny});
            }
        }
        // for (int i = 0; i <= h + 1; i++) {
        //     for (int j = 0; j <= w + 1; j++) {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // for (int i = 0; i <= h + 1; i++) {
        //     for (int j = 0; j <= w + 1; j++) {
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        // cout << "\n";

        cout << ans << '\n';
    }
}