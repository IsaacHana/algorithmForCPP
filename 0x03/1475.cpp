#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, ans = 0;
    int arr[10] = {};
    cin >> num;

    while (num > 0) {
        arr[num % 10]++;
        num /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) continue;
        ans = max(ans, arr[i]);
    }

    ans = max(ans, (arr[6] + arr[9] + 1) / 2);

    cout << ans;
}