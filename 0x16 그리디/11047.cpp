#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    int arr[12];
    int ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = n - 1; i >= 0; i--) {
        ans += k / arr[i];
        k %= arr[i];
    }

    cout << ans << '\n';
}