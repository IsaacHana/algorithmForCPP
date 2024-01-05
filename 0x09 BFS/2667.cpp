#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int board[N][N] = {};

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            board[i][j] = str[j] - '0';
        }
    }

    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> PQ;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) continue;
            cnt++;

            queue<pair<int, int>> Q;
            Q.push({i, j});
            board[i][j] = 0;

            int area = 0;
            while (!Q.empty()) {
                auto cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (board[nx][ny] == 0) continue;

                    board[nx][ny] = 0;
                    Q.push({nx, ny});
                }
                area++;
            }
            PQ.push(area);
        }
    }

    cout << cnt << '\n';
    while (!PQ.empty()) {
        cout << PQ.top() << '\n';
        PQ.pop();
    }
}