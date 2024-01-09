#include <bits/stdc++.h>
using namespace std;

int dist[200002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    const int MX = 200000;
    fill(dist, dist + MX, -1);
    deque<int> DQ;
    DQ.push_back(N);
    dist[N] = 0;

    while (dist[K] == -1) {
        auto cur = DQ.front();
        DQ.pop_front();

        int double_nxt = cur * 2;
        if (double_nxt < MX && dist[double_nxt] == -1) {
            dist[double_nxt] = dist[cur];
            DQ.push_front(double_nxt);
        }

        for (int nxt : {cur - 1, cur + 1}) {
            if (nxt < 0 || nxt >= MX) continue;
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            DQ.push_back(nxt);
        }
    }
    cout << dist[K];
}