#include <bits/stdc++.h>
using namespace std;

int board[502][502];
bool vis[502][502];
int n, m;

int mx_area = 0;
int cnt = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void board_init() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];
}

void bfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0 || vis[i][j]) continue;  // 0 = 공백 , vis = 방문
            cnt++;                                        // 공백도 아니고 방문한적도 없으니 그림의 갯수 추가

            queue<pair<int, int>> Q;
            vis[i][j] = true;  // 그림의 처음 부분 방문
            Q.push({i, j});    // 그림의 처음 부분 삽입
            int area = 0;
            while (!Q.empty()) {
                area++;
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || board[nx][ny] == 0) continue;
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }

            mx_area = max(mx_area, area);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    board_init();

    bfs();

    cout << cnt << '\n' << mx_area;
}