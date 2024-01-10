#include <bits/stdc++.h>
using namespace std;

int dist[100001];
int prv[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    queue<int> Q;
    Q.push(N);
    dist[N] = 1;

    while (dist[K] == 0) {
        auto cur = Q.front();
        Q.pop();

        for (int nxt : {cur - 1, cur + 1, cur * 2}) {
            if (nxt < 0 || nxt > 100000) continue;
            if (dist[nxt]) continue;

            dist[nxt] = dist[cur] + 1;
            prv[nxt] = cur;
            Q.push(nxt);
        }
    }

    cout << dist[K] - 1 << '\n';

    int i = K;
    stack<int> S;
    S.push(i);
    while (i != N) {
        S.push(prv[i]);
        i = prv[i];
    }
    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
}
