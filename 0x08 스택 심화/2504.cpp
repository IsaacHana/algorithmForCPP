#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long ans = 0;
    stack<char> S;
    bool isValid = true;
    string s;
    cin >> s;
    int temp = 1;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if (c == '(') {
            temp *= 2;
            S.push(c);
        } else if (c == '[') {
            temp *= 3;
            S.push(c);
        } else {  // ')' || ']'
            char prev = s[i - 1];
            if (c == ')') {
                if (S.empty() || S.top() != '(') {
                    isValid = false;
                    break;
                }
                if (prev == '(') {
                    ans += temp;
                }
                temp /= 2;

                S.pop();
            } else {  // ']'
                if (S.empty() || S.top() != '[') {
                    isValid = false;
                    break;
                }

                if (prev == '[') {
                    ans += temp;
                }
                temp /= 3;

                S.pop();
            }
        }
    }

    if (!S.empty()) isValid = false;

    if (isValid) {
        cout << ans;
    } else {
        cout << 0;
    }
}
