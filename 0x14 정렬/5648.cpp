#include <bits/stdc++.h>
using namespace std;

vector<long long> vec;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string val;
    while (n--) {
        cin >> val;
        reverse(val.begin(), val.end());

        vec.push_back(stoll(val));
    }

    sort(vec.begin(), vec.end());

    for (long long v : vec) {
        cout << v << '\n';
    }
}