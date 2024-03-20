#include <bits/stdc++.h>
using namespace std;

int N;
int a[52][10];
int b[52][10];

int player[10];
bool vis[10];
int ans = 0;

// 점수 계산
void calScore() {
    int total = 0;
    int cur = 1;

    for (int i = 1; i <= N; i++) {
        int bit = 0;
        int out = 0;

        while (out < 3) {
            if (cur > 9) cur = 1;

            int hit = b[i][cur];

            if (hit == 0) {
                out += 1;
            } else {
                int score = 0;

                bit <<= 1;
                bit += 1;

                if (bit >= 8) {
                    score += 1;
                    bit -= 8;
                }

                for (int i = 0; i < hit - 1; i++) {
                    bit <<= 1;
                    if (bit >= 8) {
                        score += 1;
                        bit -= 8;
                    }
                }

                total += score;
            }

            cur += 1;
        }
    }

    ans = max(ans, total);
}

void dfs(int depth) {
    if (depth == 10) {
        // for (int i = 1; i <= 9; i++) {
        //     cout << player[i] << ' ';
        // }
        // cout << '\n';

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= 9; j++) {
                b[i][j] = a[i][player[j]];
            }
        }

        calScore();

        return;
    }

    // 4번타자 고정
    if (depth == 4) {
        player[depth] = 1;
        dfs(depth + 1);
        return;
    }

    for (int i = 2; i <= 9; i++) {
        if (vis[i]) continue;
        player[depth] = i;
        vis[i] = true;
        dfs(depth + 1);
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 2
    // 4 0 0 1 1 1 0 0 0
    // 0 0 0 0 0 0 0 0 0
    // 백트래킹
    // 1 1 1 4 0 0 0 0 0
    // 0 0 0 4 0 0 0 0 0
    // 최대 점수 구하기
    // bitmask 0 0 0 -> {1일경우 밀고 1넣기} 0 0 1
    // bitmask 0 1 1(3) -> {2일경우 그냥 밀고 1넣기 + 그냥 밀기} 1 1 0
    // bitmask 1 1 1 (7) -> {4일경우 밀고 1넣기 + 그냥 3번 밀기} 0 0 0
    // 8 이상이되면 ans += 1 그리고 bit에선 8 빼주기

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> a[i][j];
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= 9; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    dfs(1);

    cout << ans << '\n';
}