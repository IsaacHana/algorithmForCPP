#include <bits/stdc++.h>
using namespace std;

const int MX = 500000;
int dist[2][MX + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < 2; i++) fill(dist[i], dist[i] + MX + 1, -1);

    queue<pair<int, int>> NQ;
    queue<pair<int, int>> KQ;

    NQ.push({N, 0});
    dist[0][N] = 0;

    while (!NQ.empty()) {
        int x, time;
        tie(x, time) = NQ.front();
        NQ.pop();
        int nxt_time = time + 1;

        for (auto nxt : {x + 1, x - 1, x * 2}) {
            if (nxt < 0 || nxt > MX) continue;
            if (dist[nxt_time % 2][nxt] != -1) continue;
            dist[nxt_time % 2][nxt] = nxt_time;
            NQ.push({nxt, nxt_time});
        }
    }
    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < 30; j++) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    KQ.push({K, 0});
    while (!KQ.empty()) {
        int x, time;
        tie(x, time) = KQ.front();
        KQ.pop();

        if (dist[time % 2][x] <= time) {
            cout << time << '\n';
            return 0;
        }

        int nxt_time = time + 1;
        int exp = x + nxt_time;
        // cout << x << " " << exp << " " << dist[time % 2][x + time] << " " << nxt_time << '\n';
        if (exp > MX) continue;

        KQ.push({exp, nxt_time});
    }

    cout << -1 << "\n";
}