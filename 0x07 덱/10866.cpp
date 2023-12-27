#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;
    int N;
    cin >> N;
    while (N--) {
        string cmd;
        cin >> cmd;
        if (cmd == "push_back") {
            int val;
            cin >> val;
            DQ.push_back(val);
        } else if (cmd == "push_front") {
            int val;
            cin >> val;
            DQ.push_front(val);
        } else if (cmd == "pop_front") {
            if (!DQ.empty()) {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "pop_back") {
            if (!DQ.empty()) {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "front") {
            if (!DQ.empty()) {
                cout << DQ.front() << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "back") {
            if (!DQ.empty()) {
                cout << DQ.back() << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else if (cmd == "size") {
            cout << DQ.size() << '\n';
        } else if (cmd == "empty") {
            cout << DQ.empty() << '\n';
        }
    }
}