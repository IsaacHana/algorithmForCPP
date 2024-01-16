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

    queue<int> Q;
    Q.push(N);
    dist[N] = 0;

    while (dist[K] == -1) {
        auto cur = Q.front();
        Q.pop();

        for (int nxt : {cur - 1, cur + 1, cur * 2}) {
            if (nxt < 0 || nxt > MX) continue;
            if (dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }

    cout << dist[K] << '\n';
}