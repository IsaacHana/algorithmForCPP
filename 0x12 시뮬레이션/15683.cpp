#include <bits/stdc++.h>
using namespace std;

int N, M;

int board[10][10];
int copy_board[10][10];

vector<pair<int, int>> cctv;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void watch(int x, int y, int dir) {
    dir %= 4;
    while (true) {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= N || y < 0 || y >= M) return;
        if (copy_board[x][y] == 6) return;
        if (copy_board[x][y] != 0) continue;

        copy_board[x][y] = 7;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];

            if (board[i][j] == 0) {
                ans++;
                continue;
            }
            if (board[i][j] == 6) continue;
            cctv.push_back({i, j});
        }
    }

    for (int cur = 0; cur < 1 << (2 * cctv.size()); cur++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                copy_board[i][j] = board[i][j];
            }
        }

        int brute = cur;

        for (int i = 0; i < cctv.size(); i++) {
            int dir = brute % 4;
            brute /= 4;

            int x = cctv[i].first;
            int y = cctv[i].second;

            if (board[x][y] == 1) {
                watch(x, y, dir);
            } else if (board[x][y] == 2) {
                watch(x, y, dir);
                watch(x, y, dir + 2);
            } else if (board[x][y] == 3) {
                watch(x, y, dir);
                watch(x, y, dir + 1);
            } else if (board[x][y] == 4) {
                watch(x, y, dir);
                watch(x, y, dir + 1);
                watch(x, y, dir + 2);
            } else {
                watch(x, y, dir);
                watch(x, y, dir + 1);
                watch(x, y, dir + 2);
                watch(x, y, dir + 3);
            }
        }

        int cnt = 0;
        // cout << '\n';
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // cout << copy_board[i][j] << ' ';
                if (copy_board[i][j] == 0) {
                    cnt += 1;
                }
            }
            // cout << '\n';
        }
        // cout << cnt << '\n';
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
}