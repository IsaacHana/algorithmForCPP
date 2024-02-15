#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) v.push_back(i < M ? 0 : 1);
    // for (int i = 0; i < N; i++) cout << v[i] << ' ';
    do {
        for (int i = 0; i < N; i++)
            if (v[i] == 0) cout << i + 1 << ' ';
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));
}