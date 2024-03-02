#include <bits/stdc++.h>
using namespace std;

int board[21][21];

const int BOTTOM = 1;
const int FRONT = 2;
const int RIGHT = 3;
const int LEFT = 4;
const int BACK = 5;
const int TOP = 6;

int dice[7];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void print_dice() {
    for (int i = 1; i < 7; i++) {
        cout << dice[i] << ' ';
    }
    cout << '\n';
}

void roll(int dir) {
    if (dir == 1) {
        swap(dice[BOTTOM], dice[RIGHT]);
        swap(dice[RIGHT], dice[LEFT]);
        swap(dice[RIGHT], dice[TOP]);
    } else if (dir == 2) {
        swap(dice[BOTTOM], dice[LEFT]);
        swap(dice[LEFT], dice[RIGHT]);
        swap(dice[LEFT], dice[TOP]);
    } else if (dir == 3) {
        swap(dice[FRONT], dice[TOP]);
        swap(dice[TOP], dice[BACK]);
        swap(dice[BACK], dice[BOTTOM]);
    } else if (dir == 4) {
        swap(dice[TOP], dice[FRONT]);
        swap(dice[FRONT], dice[BOTTOM]);
        swap(dice[BOTTOM], dice[BACK]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    stack<pair<int, int>> s;
    s.push({x, y});

    int dir;
    while (K--) {
        int cx, cy;
        tie(cx, cy) = s.top();
        s.pop();

        cin >> dir;

        int nx = cx + dx[dir - 1];
        int ny = cy + dy[dir - 1];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            s.push({cx, cy});
            continue;
        }

        roll(dir);

        if (board[nx][ny] == 0)
            board[nx][ny] = dice[BOTTOM];
        else {
            dice[BOTTOM] = board[nx][ny];
            board[nx][ny] = 0;
        }

        // print_dice();
        cout << dice[TOP] << '\n';
        s.push({nx, ny});
    }

    // dice[1] = 1;
    // roll(1);
    // print_dice();
    // roll(2);
    // print_dice();
    // roll(3);
    // print_dice();
    // roll(4);
    // print_dice();
}