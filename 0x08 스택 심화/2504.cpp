#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> S;
    string str;
    cin >> str;
    long long ans = 0;
    long long num = 1;

    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '(') {
            S.push(c);
            num *= 2;
        } else if (c == '[') {
            S.push(c);
            num *= 3;
        } else {
            char prev = str[i - 1];
            if (c == ')') {
                if (S.empty() || S.top() != '(') {
                    cout << 0;
                    return 0;
                }
                if (prev == '(') ans += num;
                num /= 2;
            } else if (c == ']') {
                if (S.empty() || S.top() != '[') {
                    cout << 0;
                    return 0;
                }
                if (prev == '[') ans += num;
                num /= 3;
            }
            S.pop();
        }
    }

    if (S.empty())
        cout << ans;
    else
        cout << 0;
}