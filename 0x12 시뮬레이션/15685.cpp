#include <bits/stdc++.h>
using namespace std;

int board[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int x, y, d, g;

    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;

        board[y][x] = 1;

        deque<int> dq;
        dq.push_back(d);

        for (int j = 0; j < g; j++) {
            int dqSize = dq.size();

            for (int k = dqSize - 1; k >= 0; k--) {
                dq.push_back((dq[k] + 1) % 4);
            }
        }

        while (!dq.empty()) {
            auto cur = dq.front();
            dq.pop_front();

            x += dx[cur];
            y += dy[cur];

            board[y][x] = 1;
        }
    }

    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int ans = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (!board[i][j]) continue;
            if (board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) ans++;
        }
    }
    cout << ans << '\n';
}