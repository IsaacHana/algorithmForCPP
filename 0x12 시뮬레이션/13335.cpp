#include <bits/stdc++.h>
using namespace std;

int trucks[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int n, w, L, l = 0;
    cin >> n >> w >> L;

    queue<int> truck;
    queue<int> bridge;

    int weight;
    for (int i = 0; i < n; i++) {
        cin >> weight;
        truck.push(weight);
    }

    for (int i = 0; i < w; i++) {
        bridge.push(0);
    }

    while (!bridge.empty()) {
        l -= bridge.front();
        bridge.pop();
        ans += 1;

        if (!truck.empty()) {
            auto cw = truck.front();
            if (l + cw <= L) {
                truck.pop();
                bridge.push(cw);
                l += cw;
            } else {
                bridge.push(0);
            }
        }
    }

    cout << ans << '\n';
}