#include <bits/stdc++.h>
using namespace std;

const int CYCLE = -1;

int board[100001];
int vis[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        fill(vis + 1, vis + N + 1, 0);

        for (int i = 1; i <= N; i++) {
            cin >> board[i];
        }

        int ans = N;
        for (int i = 1; i <= N; i++) {
            if (vis[i]) continue;
            int cur = i;
            int cnt = 0;
            while (true) {
                vis[cur] = i;
                cur = board[cur];
                if (vis[cur] == i) {
                    while (vis[cur] != CYCLE) {
                        cnt++;
                        vis[cur] = CYCLE;
                        cur = board[cur];
                    }
                    break;
                } else if (vis[cur]) {
                    break;
                }
            }
            ans -= cnt;
        }
        cout << ans << '\n';
    }
}