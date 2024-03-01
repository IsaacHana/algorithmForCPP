#include <bits/stdc++.h>
using namespace std;

const int GEAR_CNT = 4;
const int TEETH_CNT = 8;
string gear[GEAR_CNT + 1];

int dx[2] = {1, -1};

void rotate(int idx, int dir) {
    if (dir == 1) {
        char tmp = gear[idx][TEETH_CNT - 1];
        for (int i = TEETH_CNT - 1; i > 0; i--) {
            gear[idx][i] = gear[idx][i - 1];
        }
        gear[idx][0] = tmp;
    } else {
        char tmp = gear[idx][0];
        for (int i = 1; i <= TEETH_CNT - 1; i++) {
            gear[idx][i - 1] = gear[idx][i];
        }
        gear[idx][TEETH_CNT - 1] = tmp;
    }
}

void magnetic(int idx, int dir) {
    vector<pair<int, int>> v;
    queue<pair<int, int>> q;
    bool vis[GEAR_CNT + 1] = {};
    q.push({idx, dir});

    vis[idx] = true;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        v.push_back(cur);

        for (int dir = 0; dir < 2; dir++) {
            int nx = cur.first + dx[dir];
            if (nx < 1 || nx > GEAR_CNT) continue;
            if (vis[nx]) continue;

            if (cur.first < nx) {
                if (gear[cur.first][2] != gear[nx][6]) {
                    q.push({nx, -1 * cur.second});
                    vis[nx] = true;
                }
            } else if (cur.first > nx) {
                if (gear[nx][2] != gear[cur.first][6]) {
                    q.push({nx, -1 * cur.second});
                    vis[nx] = true;
                }
            }
        }
    }

    for (auto r : v) {
        // cout << r.first << " : " << r.second << '\n';
        rotate(r.first, r.second);
    }

    // for (int i = 1; i <= GEAR_CNT; i++) {
    //     for (int j = 0; j < TEETH_CNT; j++) {
    //         cout << gear[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= GEAR_CNT; i++) {
        cin >> gear[i];
    }

    // rotate(1, 1);
    // for (int j = 0; j < TEETH_CNT; j++) {
    //     cout << gear[1][j] << ' ';
    // }
    // rotate(1, -1);
    // for (int j = 0; j < TEETH_CNT; j++) {
    //     cout << gear[1][j] << ' ';
    // }
    int K;
    cin >> K;

    int idx, dir;
    for (int i = 0; i < K; i++) {
        cin >> idx >> dir;
        magnetic(idx, dir);
    }
    int ans = 0;
    for (int i = 1; i <= GEAR_CNT; i++) {
        // cout << (1 << (i - 1)) << '\n';
        if (gear[i][0] == '1') ans += (1 << (i - 1));
    }
    cout << ans << '\n';
}