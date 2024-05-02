#include <bits/stdc++.h>
using namespace std;

int d[1005][1005];

// ACAYKP
// CAPCAK

// 0 1 2 3 4 5 6 6
// 1 0 1
// 2 1 
// 3 1
// 4 1
// 5 1
// 6 1

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int len_a = a.length();
    int len_b = b.length();

    for (int i = 1; i <= len_a; i++) {
        for (int j = 1; j <= len_b; j++) {
            if (a[i - 1] == b[j - 1])
                d[i][j] = d[i - 1][j - 1] + 1;
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }

    cout << d[len_a][len_b] << '\n';
}