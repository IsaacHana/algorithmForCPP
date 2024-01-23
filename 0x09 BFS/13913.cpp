#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;
int dist[MX + 1];
int previous[MX + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    queue<int> Q;
    Q.push(N);
    dist[N] = 1;

    cout << '\n';
    while (!dist[K]) {
        auto cur = Q.front();
        Q.pop();

        for (auto nxt : {cur - 1, cur + 1, cur << 1}) {
            if (nxt < 0 || nxt > MX) continue;
            if (dist[nxt]) continue;

            dist[nxt] = dist[cur] + 1;
            previous[nxt] = cur;
            Q.push(nxt);
        }
    }

    cout << dist[K] - 1 << '\n';

    stack<int> S;
    S.push(K);
    int cur = K;

    while (cur != N) {
        cur = previous[cur];
        S.push(cur);
    }

    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
}