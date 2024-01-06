#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string str;
        getline(cin, str);
        if (str == ".") break;

        stack<char> S;
        bool isValid = true;
        for (char c : str) {  // ���ڿ��� �ϳ��� ���ڴ�.
            if (c == '(' || c == '[')
                S.push(c);  // ���� ��ȣ��� stack.push()
            else {
                if (c == ')') {
                    if (S.empty() || S.top() != '(') {  // 2-1, 2-2
                        isValid = false;
                        break;
                    }
                    S.pop();  // 2-3
                }
                if (c == ']') {
                    if (S.empty() || S.top() != '[') {  // 2-1, 2-2
                        isValid = false;
                        break;
                    }
                    S.pop();  // 2-3
                }
            }
        }

        if (!S.empty()) isValid = false;  // 3

        if (isValid)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}