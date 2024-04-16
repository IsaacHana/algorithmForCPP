#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<tuple<int, int, int, string>> vec;

    while (N--) {
        string name;
        int korean, english, mathematics;
        cin >> name >> korean >> english >> mathematics;
        vec.push_back({-korean, english, -mathematics, name});
    }

    sort(vec.begin(), vec.end());

    for (auto& v : vec) {
        cout << get<3>(v) << '\n';
    }
}