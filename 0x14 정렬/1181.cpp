#include <bits/stdc++.h>
using namespace std;

bool comp(const string& a, const string& b) {
    int al = a.length();
    int bl = b.length();

    if (al != bl) return al < bl;
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<string> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end(), comp);

    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (auto& v : vec) {
        cout << v << '\n';
    }
}