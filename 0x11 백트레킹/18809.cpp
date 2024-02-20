#include <bits/stdc++.h>
using namespace std;

const int LAKE = 0;
const int GROUND = 1;
const int POSSIBLE = 2;

const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int N, M, G, R;
int board[52][52];
vector<pair<int, int>> v;
int v_size;
int brute[10];
int arr[10];
int vis[10];
int ans = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<pair<int, int>> q;
    pair<int, int> state[52][52];  // 거리, 종류
    for (int i = 0; i < v_size; i++) {
        if (arr[i] != EMPTY) {
            state[v[i].first][v[i].second] = {0, arr[i]};
            q.push(v[i]);
        }
    }

    // for (int i = 0; i <= N + 1; i++) {
    //     for (int j = 0; j <= M + 1; j++) {
    //         cout << state[i][j].second << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    int cnt = 0;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        int cur_dis = state[x][y].first;
        int cur_tpye = state[x][y].second;
        if (cur_tpye == FLOWER) continue;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (board[nx][ny] == LAKE) continue;  // 호수 일 경우

            int nxt_dis = state[nx][ny].first;
            int nxt_type = state[nx][ny].second;

            if (nxt_type == EMPTY) {
                state[nx][ny] = {cur_dis + 1, cur_tpye};
                q.push({nx, ny});
            } else if (nxt_type == RED) {
                if (cur_tpye == GREEN && nxt_dis == cur_dis + 1) {
                    state[nx][ny].second = FLOWER;
                    cnt++;
                }
            } else if (nxt_type == GREEN) {
                if (cur_tpye == RED && nxt_dis == cur_dis + 1) {
                    state[nx][ny].second = FLOWER;
                    cnt++;
                }
            }
        }
    }

    // for (int i = 0; i <= N + 1; i++) {
    //     for (int j = 0; j <= M + 1; j++) {
    //         cout << state[i][j].second << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    return cnt;
}

void dfs(int depth) {
    if (depth == v_size) {
        // for (int i = 0; i < v_size; i++) {
        //     cout << arr[i] << ' ';
        // }
        // cout << "\n";

        ans = max(ans, bfs());
        return;
    }

    int tmp = -1;
    for (int i = 0; i < v_size; i++) {
        if (tmp == brute[i]) continue;
        if (vis[i]) continue;

        arr[depth] = brute[i];
        tmp = arr[depth];

        vis[i] = true;
        dfs(depth + 1);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> G >> R;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
            if (board[i][j] == POSSIBLE) v.push_back({i, j});
        }
    }

    v_size = v.size();

    // for (int i = 0; i <= N + 1; i++) {
    //     for (int j = 0; j <= M + 1; j++) {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // cout << v_size << '\n';

    fill(brute + v_size - G - R, brute + v_size - R, GREEN);
    fill(brute + v_size - R, brute + v_size, RED);

    // cout << "brute" << '\n';
    // for (int i = 0; i < v_size; i++) {
    //     cout << brute[i] << ' ';
    // }
    // cout << "\n=======\n";

    dfs(0);

    cout << ans << '\n';
}