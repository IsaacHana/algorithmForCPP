#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[21][21];
int copy_board[21][21];

struct Cctv {
    int x;
    int y;
    int model;
    int direct;
};

vector<Cctv> cctvs;
vector<int> arr;
int dir[4] = {0, 1, 2, 3};
int cctv_size;
bool vis[4];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int mx = 0;

void watch(int x, int y, int dir) {
    dir %= 4;
    while (true) {
        x += dx[dir];
        y += dy[dir];
        if (x < 0 || x >= N || y < 0 || y >= M) return;
        if (copy_board[x][y] == 6) return;
        if (copy_board[x][y] != 0) continue;
        copy_board[x][y] = 7;
    }
}

void dfs(int depth) {
    if (depth == cctv_size) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                copy_board[i][j] = board[i][j];
            }
        }

        for (int i = 0; i < cctv_size; i++) {
            cctvs[i].direct = arr[i];
            // cout << arr[i] << ' ';
        }
        // cout << '\n';

        for (Cctv cctv : cctvs) {
            int dir = cctv.direct;
            if (cctv.model == 1) {
                watch(cctv.x, cctv.y, cctv.direct);
            } else if (cctv.model == 2) {
                watch(cctv.x, cctv.y, cctv.direct);
                watch(cctv.x, cctv.y, cctv.direct + 2);
            } else if (cctv.model == 3) {
                watch(cctv.x, cctv.y, cctv.direct);
                watch(cctv.x, cctv.y, cctv.direct + 1);
            } else if (cctv.model == 4) {
                watch(cctv.x, cctv.y, cctv.direct);
                watch(cctv.x, cctv.y, cctv.direct + 1);
                watch(cctv.x, cctv.y, cctv.direct + 2);
            } else if (cctv.model == 5) {
                watch(cctv.x, cctv.y, cctv.direct);
                watch(cctv.x, cctv.y, cctv.direct + 1);
                watch(cctv.x, cctv.y, cctv.direct + 2);
                watch(cctv.x, cctv.y, cctv.direct + 3);
            }
        }
        int cnt = 0;
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << copy_board[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (copy_board[i][j] == 0) cnt++;
            }
        }
        mx = min(mx, cnt);
        return;
    }

    for (int i = 0; i < 4; i++) {
        arr.push_back(dir[i]);
        dfs(depth + 1);
        arr.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];

            if (board[i][j] == 0) {
                mx++;
                continue;
            }

            if (board[i][j] == 6) continue;

            Cctv cctv;
            cctv.x = i;
            cctv.y = j;
            cctv.model = board[i][j];
            cctvs.push_back(cctv);
        }
    }

    cctv_size = cctvs.size();

    dfs(0);

    cout << mx << '\n';
}