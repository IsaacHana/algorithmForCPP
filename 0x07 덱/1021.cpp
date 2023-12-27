#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> DQ;
    deque<int> DQ2;
    int N, M;
    long long ans = 0;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        DQ.push_back(i);
        DQ2.push_back(i);
    }

    while (M--) {
        int val;
        cin >> val;

        while (DQ.front() != val && DQ2.front() != val) {
            DQ.push_back(DQ.front());
            DQ.pop_front();

            DQ2.push_front(DQ2.back());
            DQ2.pop_back();

            ans++;
        }

        if (DQ.front() == val) {
            DQ.pop_front();
            DQ2 = DQ;
        } else {
            DQ2.pop_front();
            DQ = DQ2;
        }
    }
    cout << ans;
}

// 10 3
// 2 9 5

// 1 2 3 4 5 6 7 8 9 10
// 1   3 4 5 6 7 8 9 10  //  + 1
// 1   3 4 5 6 7 8   10  //  + 3
// 1   3 4   6 7 8   10  //  + 4