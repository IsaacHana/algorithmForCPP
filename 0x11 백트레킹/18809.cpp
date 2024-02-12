#include <bits/stdc++.h>
using namespace std;

const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int N, M, G, R, GR;
int board[52][52];
vector<pair<int, int>> v;
int total;
int green_red[10];
int arr[10];
bool vis[10];
int ans = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs() {
    int cnt = 0;
    pair<int, int> state[52][52];  // 거리, 색깔

    queue<pair<int, int>> Q;
    for (int i = 0; i < total; i++) {
        if (arr[i] == GREEN || arr[i] == RED) {
            state[v[i].first][v[i].second] = {0, arr[i]};
            Q.push(v[i]);
        }
    }

    while (!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front();
        Q.pop();

        int cur_time = state[x][y].first;
        int cur_color = state[x][y].second;

        if (cur_color == FLOWER) continue;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] == 0) continue;  // 호수

            int nxt_time = state[nx][ny].first;
            int nxt_color = state[nx][ny].second;
            // 배양액이 없는 땅일 때
            if (nxt_color == 0) {
                state[nx][ny] = {cur_time + 1, cur_color};
                Q.push({nx, ny});
            }
            // 초록 배양액
            else if (nxt_color == GREEN) {
                if (cur_color == RED && nxt_time == cur_time + 1) {  // 빨간색 배양액과 동시에 접근한다면
                    cnt++;                                           // 꽃의 갯수 증가
                    state[nx][ny].second = FLOWER;                   // 꽃이 핀 상태
                }
            }
            // 빨간
            else if (nxt_color == RED) {
                if (cur_color == GREEN && nxt_time == cur_time + 1) {
                    cnt++;
                    state[nx][ny].second = FLOWER;
                }
            }
        }
    }

    return cnt;
}

void backTracking(int depth) {
    // base case
    if (depth == total) {
        // for (int i = 0; i < total; i++) {
        //     cout << arr[i] << ' ';
        // }
        // cout << '\n';
        ans = max(ans, bfs());
        return;
    }

    // N과 M (9) 15663
    int tmp = -1;
    for (int i = 0; i < total; i++) {
        if (tmp == green_red[i]) continue;
        if (vis[i]) continue;

        arr[depth] = green_red[i];
        tmp = arr[depth];
        vis[i] = true;
        backTracking(depth + 1);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> G >> R;

    GR = G + R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) v.push_back({i, j});
        }
    }

    total = v.size();

    fill(green_red + total - G - R, green_red + total - R, GREEN);
    fill(green_red + total - R, green_red + total, RED);

    // cout << "========\n";
    // for (int i = 0; i < total; i++) {
    //     cout << green_red[i] << ' ';
    // }
    // cout << "\n========\n";
    backTracking(0);

    cout << ans << '\n';
}