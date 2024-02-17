#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int tmp[1002];

void merge(int start, int end) {
    int mid = (start + end) / 2;
    int l = start;
    int r = mid;
    for (int i = start; i < end; i++) {
        if (r == end)
            tmp[i] = arr[l++];
        else if (l == mid)
            tmp[i] = arr[r++];
        else if (arr[l] <= arr[r])
            tmp[i] = arr[l++];
        else
            tmp[i] = arr[r++];
    }
    for (int i = start; i < end; i++) arr[i] = tmp[i];
}

void merge_sort(int start, int end) {
    if (start + 1 == end) return;
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, end);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N;
    M = N;
    int val;
    while (M--) {
        cin >> val;
        arr.push_back(val);
    }
    merge_sort(0, N);
    for (int i = 0; i < N; i++) cout << arr[i] << '\n';
}