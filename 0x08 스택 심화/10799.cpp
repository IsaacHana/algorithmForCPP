#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long ans = 0;
    stack<char> S;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            S.push(s[i]);
        } else {  // ')'
            S.pop();
            if (s[i - 1] == '(') {  // lazer
                ans += S.size();
            } else {  // bar
                ans++;
            }
        }
    }

    cout << ans;
}