#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string sentence;
        getline(cin, sentence);
        if (sentence == ".") break;

        stack<char> S;
        bool isValid = true;

        for (char c : sentence) {
            if (c == '(' || c == '[') S.push(c);
            if (c == ')') {
                if (S.empty() || S.top() != '(') {
                    isValid = false;
                    break;
                }
                S.pop();
            }
            if (c == ']') {
                if (S.empty() || S.top() != '[') {
                    isValid = false;
                    break;
                }
                S.pop();
            }
        }

        if (!S.empty()) isValid = false;

        if (isValid) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}