#include <bits/stdc++.h>
using namespace std;

const int EMPTY = 0;
const int WALL = 1;
const int SNAKE = 2;
const int APPLE = 3;

int board[102][102];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int move(int nx, int ny, int cx, int cy, int len) {}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, L, X;
    char C;

    cin >> N;
    cin >> K;
    for (int i = 0; i <= N + 1; i++) {
        if (i == 0 || i == N + 1) {
            fill(board[i], board[i] + N + 2, WALL);
        } else {
            board[i][0] = WALL;
            board[i][N + 1] = WALL;
        }
    }

    int x, y;
    while (K--) {
        cin >> x >> y;
        board[x][y] = APPLE;
    }

    cin >> L;
    queue<pair<int, char>> q;
    while (L--) {
        cin >> X >> C;
        q.push({X, C});
    }

    // for (int i = 0; i <= N + 1; i++) {
    //     for (int j = 0; j <= N + 1; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int time = 0;
    int cd = 1;
    deque<pair<int, int>> snake;
    snake.push_back({1, 1});

    while (true) {
        cd %= 4;

        int hx, hy;
        tie(hx, hy) = snake.front();

        int nx = hx + dx[cd];
        int ny = hy + dy[cd];

        time++;

        if (board[nx][ny] == WALL) break;
        bool flag = false;
        for (auto s : snake) {
            if (s.first == nx && s.second == ny) flag = true;
        }
        if (flag) break;

        snake.push_front({nx, ny});

        if (board[nx][ny] == APPLE) {
            board[nx][ny] = EMPTY;
            int tx, ty;
            tie(tx, ty) = snake.back();
            snake.push_back({tx, ty});
        }

        snake.pop_back();

        if (!q.empty()) {
            if (time == q.front().first) {
                auto dir = q.front();
                if (dir.second == 'L')
                    cd += 3;
                else if (dir.second == 'D')
                    cd += 1;
                q.pop();
            }
        }
        // cout << "===========" << time << "===========\n";
        // int copy[102][102] = {};
        // for (int i = 0; i <= N + 1; i++) {
        //     for (int j = 0; j <= N + 1; j++) {
        //         copy[i][j] = board[i][j];
        //     }
        // }
        // for (int i = 0; i < snake.size(); i++) {
        //     auto cur = snake[i];
        //     copy[cur.first][cur.second] = SNAKE;
        // }
        // for (int i = 0; i <= N + 1; i++) {
        //     for (int j = 0; j <= N + 1; j++) {
        //         cout << copy[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    cout << time << '\n';
}