#include <bits/stdc++.h>
using namespace std;

void parse(string& arr, deque<int>& DQ) {
    int cur = 0;
    for (int i = 1; i < arr.size() - 1; i++) {
        if (arr[i] == ',') {
            DQ.push_back(cur);
            cur = 0;
        } else {
            cur = 10 * cur + (arr[i] - '0');
        }
    };

    if (cur != 0) DQ.push_back(cur);
}

void print_result(deque<int> DQ) {
    cout << "[";
    for (int i = 0; i < DQ.size(); i++) {
        cout << DQ[i];
        if (i + 1 != DQ.size()) cout << ',';
    }
    cout << "]\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        deque<int> DQ;
        string p;
        int n;
        string arr;
        cin >> p >> n >> arr;

        int rev = 0;
        bool isWrong = false;

        parse(arr, DQ);

        for (char c : p) {
            if (c == 'R') {
                rev = 1 - rev;
            } else if (c == 'D') {
                if (DQ.empty()) {
                    isWrong = true;
                    break;
                }

                if (!rev)
                    DQ.pop_front();
                else
                    DQ.pop_back();
            }
        }

        if (!isWrong) {
            if (rev) reverse(DQ.begin(), DQ.end());
            print_result(DQ);
        } else {
            cout << "error" << '\n';
        }
    }
}