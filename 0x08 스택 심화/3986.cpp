#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int ans = 0;
    while (N--) {
        stack<char> S;
        string str;
        cin >> str;

        for (char c : str) {
            if (!S.empty() && S.top() == c)
                S.pop();
            else
                S.push(c);
        }

        if (S.empty()) {
            ans++;
        }
    }

    cout << ans;
}