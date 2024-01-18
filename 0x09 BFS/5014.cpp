#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;
int dist[MX + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    fill(dist, dist + MX + 1, -1);

    queue<int> Q;
    Q.push(S);
    dist[S] = 0;

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int nxt : {cur + U, cur - D}) {
            if (nxt < 1 || nxt > F) continue;
            if (dist[nxt] != -1) continue;

            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }

    if (dist[G] == -1)
        cout << "use the stairs";
    else
        cout << dist[G];
}