#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;
int board[MX + 1];
int vis[MX + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> board[i];
        }

        int cnt = n;

        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            int cur = i;
            while (true) {
                vis[cur] = i;
                cur = board[cur];

                if (vis[cur] == i) {
                    while (vis[cur] != -1) {
                        cnt--;
                        vis[cur] = -1;
                        cur = board[cur];
                    }
                    break;
                }
                if (vis[cur]) break;
            }
        }

        cout << cnt << '\n';

        fill(vis + 1, vis + n + 1, 0);
    }
}