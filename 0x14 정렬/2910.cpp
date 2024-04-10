#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;
    cin >> N >> C;
    vector<pair<int, int>> vec;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        bool flag = false;
        for (auto& v : vec) {
            if (v.first == x) {
                flag = true;
                v.first++;
                break;
            }
        }

        if (!flag) vec.push_back({1, x});
    }

    stable_sort(vec.begin(), vec.end(), comp);

    for (auto v : vec) {
        while (v.first--) cout << v.second << ' ';
    }
}