#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        stack<char> S;
        string PS;
        cin >> PS;
        bool isValid = true;

        for (auto c : PS) {
            if (c == '(') {
                S.push(c);
            } else {  // ')'
                if (S.empty() || S.top() != '(') {
                    isValid = false;
                    break;
                }
                S.pop();
            }
        }
        if (!S.empty()) isValid = false;

        if (isValid)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}