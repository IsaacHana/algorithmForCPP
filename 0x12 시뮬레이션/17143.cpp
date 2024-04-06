#include <bits/stdc++.h>
using namespace std;

struct shark {
    int s;
    int d;
    int z;
};

int R, C, M;

vector<shark> board[102][102];
vector<shark> des[102][102];

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void print_sharks() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j].empty()) {
                cout << 0 << ' ';

            } else {
                cout << board[i][j][0].z << ' ';
            }
        }
        cout << '\n';
    }
    cout << '\n';
}

void shark_move(int i, int j) {
    shark sh = board[i][j][0];
    board[i][j].pop_back();

    // cout << "현재 위치 : " << i << " " << j << '\n';
    // cout << "현재 상태 : " << sh.d << " " << sh.s << " " << sh.z << '\n';

    if (sh.d == 1 || sh.d == 2) {
        int move = sh.s % (2 * (R - 1));

        while (move--) {
            i += dx[sh.d];
            j += dy[sh.d];
            if (i <= 0 || i > R || j <= 0 || j > C) {
                sh.d = 3 - sh.d;
                i += 2 * dx[sh.d];
                j += 2 * dy[sh.d];
            }
        }
    } else {
        int move = sh.s % (2 * (C - 1));

        while (move--) {
            i += dx[sh.d];
            j += dy[sh.d];
            if (i <= 0 || i > R || j <= 0 || j > C) {
                sh.d = 7 - sh.d;
                i += 2 * dx[sh.d];
                j += 2 * dy[sh.d];
            }
        }
    }

    // cout << "목적지 " << i << " " << j << '\n';
    // cout << "목적지 상태 " << sh.d << " " << sh.s << " " << sh.z << '\n';

    des[i][j].push_back(sh);
}

void sharks_move() {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (!board[i][j].empty()) {
                shark_move(i, j);
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            board[i][j] = des[i][j];
            des[i][j].clear();
        }
    }
    // compare size
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (board[i][j].size() > 1) {
                sort(board[i][j].begin(), board[i][j].end(), [](auto& a, auto& b) { return a.z > b.z; });
                while (board[i][j].size() > 1) board[i][j].pop_back();
            }
        }
    }
}

int cur_c = 0;
int total = 0;

void move_fisher() { cur_c++; }

void catch_shark() {
    for (int i = 1; i <= R; i++) {
        if (board[i][cur_c].empty()) continue;
        shark sh = board[i][cur_c].front();
        board[i][cur_c].pop_back();
        total += sh.z;
        break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> M;
    int r, c, s, d, z;

    while (M--) {
        cin >> r >> c >> s >> d >> z;
        shark sh = {s, d, z};
        board[r][c].push_back(sh);
    }

    // print_sharks();
    // sharks_move();
    // print_sharks();
    // sharks_move();
    // print_sharks();

    for (int i = 0; i < C; i++) {
        // print_sharks();
        move_fisher();
        catch_shark();
        sharks_move();
    }
    // print_sharks();

    cout << total << '\n';
}