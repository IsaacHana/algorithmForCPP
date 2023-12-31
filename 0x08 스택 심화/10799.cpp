#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long ans = 0;
    stack<char> S;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '(') {
            S.push(c);
        } else {  // ')'
            char prev = str[i - 1];
            S.pop();
            if (prev == '(') {  // lazer
                ans += S.size();
            } else {  // bar
                ans++;
            }
        }
    }

    cout << ans;
}