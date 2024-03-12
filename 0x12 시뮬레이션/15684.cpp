#include <bits/stdc++.h>
using namespace std;

bool ladder[32][12];
int N, M, H;
int ans = 4;

bool check() {
    for (int i = 1; i <= N; i++) {
        int tmp = i;
        for (int j = 1; j <= H; j++) {
            if (ladder[j][tmp] == 1)
                tmp += 1;
            else if (ladder[j][tmp - 1] == 1)
                tmp -= 1;
        }

        if (tmp != i) return false;
    }

    return true;
}

void dfs(int depth, int cnt) {
    // cout << "=================\n";

    // for (int i = 0; i <= H + 1; i++) {
    //     for (int j = 0; j <= N + 1; j++) {
    //         cout << ladder[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    if (depth == cnt) {
        if (check()) {
            ans = depth;
            return;
        }
        return;
    }

    for (int j = 1; j < N; j++) {
        for (int i = 1; i <= H; i++) {
            if (ladder[i][j] || ladder[i][j + 1] || ladder[i][j - 1]) continue;
            ladder[i][j] = 1;
            dfs(depth + 1, cnt);
            ladder[i][j] = 0;

            while (!ladder[i][j - 1] && !ladder[i][j + 1]) {
                if (i > H) break;
                i++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;
    int h, n;
    while (M--) {
        cin >> h >> n;
        ladder[h][n] = 1;
    }

    // for (int i = 1; i <= H; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << ladder[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 0; i < 4; i++) {
        dfs(0, i);
        if (ans < 4) {
            cout << ans;
            return 0;
        }
    }
    cout << -1;

    return 0;
}