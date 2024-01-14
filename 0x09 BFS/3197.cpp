#include <bits/stdc++.h>
using namespace std;

char board[1501][1501];
bool vis1[1501][1501];
bool vis2[1501][1501];
int R, C;
int ans = 0;
pair<int, int> S;
queue<pair<int, int>> CQ;
queue<pair<int, int>> CQ2;
queue<pair<int, int>> MQ;
queue<pair<int, int>> MQ2;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isConnect() {
    // 1. 백조 만나는지
    while (!CQ.empty()) {
        int x, y;
        tie(x, y) = CQ.front();
        CQ.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (vis1[nx][ny]) continue;

            if (board[nx][ny] == 'L') {
                return true;
                break;
            } else if (board[nx][ny] == 'X') {
                vis1[nx][ny] = true;
                CQ2.push({nx, ny});
                continue;
            }

            vis1[nx][ny] = true;
            CQ.push({nx, ny});
        }
    }

    while (!CQ2.empty()) {
        int x, y;
        tie(x, y) = CQ2.front();
        CQ2.pop();
        CQ.push({x, y});
    }

    return false;
}

// 2.빙하 녹이기
void melting() {
    while (!MQ.empty()) {
        int x, y;
        tie(x, y) = MQ.front();
        MQ.pop();
        vis2[x][y] = true;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (vis2[nx][ny]) continue;
            if (board[nx][ny] == 'X') {
                MQ2.push({nx, ny});
            }
            vis2[nx][ny] = true;
        }
    }

    while (!MQ2.empty()) {
        int x, y;
        tie(x, y) = MQ2.front();
        MQ2.pop();
        board[x][y] = '.';
        MQ.push({x, y});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 1. 백조 만날 수 있는지
    // 2. 빙판 녹이기

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'L') {
                S = {i, j};
            }
            if (board[i][j] != 'X') {
                MQ.push({i, j});
            }
        }
    }

    CQ.push(S);
    board[S.first][S.second] = '.';
    vis1[S.first][S.second] = true;
    // 3. 갯수 세기
    while (!isConnect()) {
        melting();
        ans++;
    }

    cout << ans << '\n';
}