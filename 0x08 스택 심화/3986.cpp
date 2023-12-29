#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long ans = 0;
    int N;
    cin >> N;
    while (N--) {
        stack<char> S;
        string s;
        cin >> s;

        for (auto c : s) {
            if (S.empty()) {
                S.push(c);
            } else {
                if (S.top() != c) {
                    S.push(c);
                } else {
                    S.pop();
                }
            }
        }

        if (S.empty()) {
            ans++;
        }
    }

    cout << ans;
}