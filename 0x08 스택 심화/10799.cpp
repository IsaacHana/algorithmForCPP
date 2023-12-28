#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> st;
    long long ans = 0;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        } else {  // ')'
            st.pop();
            if (s[i - 1] == '(') {  // lazer
                ans += st.size();
            } else {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}