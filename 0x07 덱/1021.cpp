#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    deque<int> DQ;
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) DQ.push_back(i);
    while (M--) {
        int val;
        cin >> val;
        int idx = find(DQ.begin(), DQ.end(), val) - DQ.begin();
        while (DQ.front() != val) {
            if (idx < DQ.size() - idx) {
                DQ.push_back(DQ.front());
                DQ.pop_front();
            } else {
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            ans++;
        }
        DQ.pop_front();
    }
    cout << ans;
}