#include <bits/stdc++.h>
using namespace std;

const int MX = 2'000'000;
const int HALF = MX / 2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> v(MX + 2);

    int val;
    while (N--) {
        cin >> val;
        v[val + HALF]++;
    }

    for (int i = 0; i <= MX; i++) {
        while (v[i]--) {
            cout << i - HALF << '\n';
        }
    }
}