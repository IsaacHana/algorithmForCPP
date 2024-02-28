#include <bits/stdc++.h>
using namespace std;

int N, M;

const int INF = 987654321;
const int EMPTY = 0;
const int HOME = 1;
const int CHICHEN = 2;

int board[52][52];

vector<pair<int, int>> home;
vector<pair<int, int>> chi;
vector<pair<int, int>> arr;

int ans = INF;

void dfs(int depth, int start) {
    if (depth == M) {
        // for (int i = 0; i < arr.size(); i++) {
        //     cout << arr[i].first << " : " << arr[i].second << '\n';
        // }
        // cout << '\n';

        int total = 0;
        for (auto cur_home : home) {
            int hx, hy;
            tie(hx, hy) = cur_home;
            int cnt = INF;
            for (auto cur_chi : arr) {
                int cx, cy;
                tie(cx, cy) = cur_chi;
                cnt = min(cnt, abs(cx - hx) + abs(cy - hy));
            }

            total += cnt;
        }

        ans = min(ans, total);
        return;
    }

    for (int i = start; i < chi.size(); i++) {
        auto c = chi[i];
        int x, y;
        tie(x, y) = c;

        arr.push_back(c);

        dfs(depth + 1, i + 1);

        arr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == HOME) home.push_back({i, j});
            if (board[i][j] == CHICHEN) chi.push_back({i, j});
        }
    }

    dfs(0, 0);

    cout << ans << '\n';
}