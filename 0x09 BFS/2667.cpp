#include <bits/stdc++.h>
using namespace std;

string board[26];
bool vis[26][26];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    queue<pair<int, int>> Q1;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '1') {
                Q1.push({i, j});
            }
        }
    }
    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> PQ;
    while (!Q1.empty()) {
        auto cur1 = Q1.front();
        Q1.pop();
        if (vis[cur1.first][cur1.second]) continue;
        cnt++;

        queue<pair<int, int>> Q2;
        vis[cur1.first][cur1.second] = true;
        Q2.push({cur1.first, cur1.second});
        int area = 0;
        while (!Q2.empty()) {
            auto cur2 = Q2.front();
            Q2.pop();
            area++;
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur2.first + dx[dir];
                int ny = cur2.second + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (board[nx][ny] == '0') continue;
                if (vis[nx][ny]) continue;

                vis[nx][ny] = true;
                Q2.push({nx, ny});
            }
        }
        PQ.push(area);
    }

    cout << cnt << '\n';
    while (!PQ.empty()) {
        cout << PQ.top() << '\n';
        PQ.pop();
    }
}