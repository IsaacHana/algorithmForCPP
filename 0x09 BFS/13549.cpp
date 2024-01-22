#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;
int dist[MX + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    fill(dist, dist + MX + 1, -1);
    deque<int> DQ;
    DQ.push_back(N);
    dist[N] = 0;

    while (dist[K] == -1) {
        auto cur = DQ.front();
        DQ.pop_front();

        if (cur * 2 <= MX && dist[cur * 2] == -1) {
            dist[cur * 2] = dist[cur];
            DQ.push_front(cur * 2);
        }

        for (auto nxt : {cur - 1, cur + 1}) {
            if (nxt < 0 || nxt > MX) continue;
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            DQ.push_back(nxt);
        }
    }

    // for (int i = 0; i < 20; i++) {
    //     cout << dist[i] << " ";
    // }
    // cout << '\n';
    cout << dist[K];
}