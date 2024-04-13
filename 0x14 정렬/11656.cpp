#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> vec;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        vec.push_back(str.substr(i));
    }
    sort(vec.begin(), vec.end());
    for (auto v : vec) cout << v << '\n';
}