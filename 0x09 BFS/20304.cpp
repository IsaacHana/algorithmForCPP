#include <bits/stdc++.h>
using namespace std;

int dist[1'000'001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, val, mx_bit = 1;
    cin >> N >> M;

    vector<int> starts;
    for (int i = 0; i < M; i++) {
        cin >> val;
        starts.push_back(val);
    }

    int tmp = N;
    while (tmp /= 2) {
        mx_bit++;
    }

    fill(dist, dist + N + 1, -1);

    queue<int> Q;

    for (auto cur : starts) {
        dist[cur] = 0;
        Q.push(cur);
    }

    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();

        for (int i = 0; i < mx_bit; i++) {
            int nxt;
            if (cur & (1 << i)) {       // i 번 비트가 1인가?
                nxt = cur & ~(1 << i);  // 1이라면 0으로 뒤집어
            } else {                    // 0이라면
                nxt = cur | (1 << i);   // 1로 뒤집어
            }
            if (nxt > N) continue;
            if (dist[nxt] >= 0) continue;

            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }

    int ans = -1;
    for (int i = 0; i <= N; i++) {
        ans = max(ans, dist[i]);
    }
    cout << ans;
}