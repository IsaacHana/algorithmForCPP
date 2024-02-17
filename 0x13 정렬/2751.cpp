#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
queue<int> q;

void merge(int start, int end) {
    int mid = (start + end) / 2;
    int l = start;
    int r = mid;

    for (int i = start; i < end; i++) {
        if (r == end)
            q.push(arr[l++]);
        else if (l == mid)
            q.push(arr[r++]);
        else if (arr[l] <= arr[r])
            q.push(arr[l++]);
        else
            q.push(arr[r++]);
    }
    for (int i = start; i < end; i++) {
        arr[i] = q.front();
        q.pop();
    }
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
    int N;
    cin >> N;
    int val;
    for (int i = 0; i < N; i++) {
        cin >> val;
        arr.push_back(val);
    }
    merge_sort(0, N);
    for (int i = 0; i < N; i++) cout << arr[i] << '\n';
}