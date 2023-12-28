#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<pair<int, int>> DQ;
    int N, L;
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;

        while (!DQ.empty() && DQ.back().second >= val) {
            DQ.pop_back();
        }

        DQ.push_back({i, val});

        if (DQ.front().first < i - L + 1) {
            DQ.pop_front();
        }

        cout << DQ.front().second << " ";
    }
}