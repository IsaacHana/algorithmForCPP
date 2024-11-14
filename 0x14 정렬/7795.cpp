#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> vec(n + m);

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            vec[i] = {a, 0};
        }

        for (int i = n; i < n + m; i++) {
            int b;
            cin >> b;
            vec[i] = {b, 1};
        }

        sort(vec.begin(), vec.end());
    
        int cnt = 0;
        int ans = 0;
    
        for (int i = 0; i < n + m; i++) {
            if (vec[i].second == 0)
                ans += cnt;
            else
                cnt++;
        }

        cout << ans << '\n';
    }
}