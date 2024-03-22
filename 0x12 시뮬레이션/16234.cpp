#include <bits/stdc++.h>
using namespace std;

int N, L, R;
int A[52][52];
bool vis[52][52];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isMoved;

void bfs(int i, int j) {
    if (vis[i][j]) return;

    int cnt = 0;
    int total = 0;

    queue<pair<int, int>> q;
    queue<pair<int, int>> visited;

    q.push({i, j});
    vis[i][j] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        cnt += 1;
        total += A[cur.first][cur.second];
        visited.push(cur);
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int diff = abs(A[cur.first][cur.second] - A[nx][ny]);
            if (diff < L || diff > R) continue;
            if (vis[nx][ny]) continue;

            q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }

    int result = total / cnt;

    if (cnt > 1) {
        isMoved = true;
    }

    while (!visited.empty()) {
        auto cur = visited.front();
        visited.pop();
        A[cur.first][cur.second] = result;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    int ans = 0;

    // 1. open gate // bfs
    while (true) {
        isMoved = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                vis[i][j] = false;
            }
        }

        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         bfs(i, j);
        //     }
        // }
        queue<pair<int, int>> q;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!vis[i][j]) q.push({i, j});
                int total = 0;
                vector<pair<int, int>> tmp;

                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        int diff = abs(A[cur.first][cur.second] - A[nx][ny]);

                        if (diff >= L && diff <= R) {
                            isMoved = 1;
                            if (!vis[cur.first][cur.second]) {
                                tmp.push_back(cur);
                                total += A[cur.first][cur.second];
                                vis[cur.first][cur.second] = 1;
                            }
                            if (!vis[nx][ny]) {
                                tmp.push_back({nx, ny});
                                total += A[nx][ny];
                                vis[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                for (int k = 0; k < tmp.size(); k++) A[tmp[k].first][tmp[k].second] = total / tmp.size();
            }
        }
        if (isMoved == false)
            break;
        else
            ans++;

        // cout << '\n';
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         cout << A[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    cout << ans << '\n';
}