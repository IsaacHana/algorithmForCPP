#include <bits/stdc++.h>
using namespace std;

int board[22][22];

int team[22];

int N, ans = (~0U >> 2);

void dfs(int depth, int start) {
    if (depth == N / 2) {
        int start = 0, link = 0;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (team[i] && team[j]) {
                    start += board[i][j] + board[j][i];
                    // cout << "start : " << start << "\n";
                } else if (!team[i] && !team[j]) {
                    link += board[i][j] + board[j][i];
                    // cout << "link : " << link << "\n";
                }
            }
        }

        ans = min(ans, abs(start - link));

        return;
    }

    for (int i = start; i < N; i++) {
        team[i] = 1;
        dfs(depth + 1, i + 1);
        team[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0);

    cout << ans << '\n';
}