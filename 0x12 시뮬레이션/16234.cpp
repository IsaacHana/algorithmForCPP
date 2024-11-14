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

    int total = 0;

    queue<pair<int, int>> q;
    queue<pair<int, int>> visited;

    q.push({i, j});
    vis[i][j] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        total += A[cur.first][cur.second];
        visited.push(cur);

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (vis[nx][ny]) continue;
            int diff = abs(A[cur.first][cur.second] - A[nx][ny]);
            if (diff < L || diff > R) continue;

            isMoved = 1;

            vis[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    int result = total / visited.size();

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

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                bfs(i, j);
            }
        }

        if (isMoved == false)
            break;
        else
            ans++;

        cout << '\n';
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << A[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    cout << ans << '\n';
}