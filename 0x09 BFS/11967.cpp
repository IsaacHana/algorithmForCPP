#include <bits/stdc++.h>
using namespace std;

int board[101][101];
bool light[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> adj[101][101];

    while (M--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        adj[x][y].push_back({a, b});
    }

    queue<pair<int, int>> Q;
    light[1][1] = 1;
    board[1][1] = 1;
    Q.push({1, 1});

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (auto neighbor : adj[cur.first][cur.second]) {
            if (board[neighbor.first][neighbor.second]) continue;
            for (int dir = 0; dir < 4; dir++) {
                int nx = neighbor.first + dx[dir];
                int ny = neighbor.second + dy[dir];

                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
                if (!board[nx][ny]) continue;
                board[nx][ny] = 1;
                Q.push({nx, ny});
                break;
            }
            light[neighbor.first][neighbor.second] = true;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (!light[nx][ny]) continue;
            if (board[nx][ny]) continue;

            board[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // cout << light[i][j] << " ";
            ans += light[i][j];
        }
        // cout << "\n";
    }

    cout << ans;
}