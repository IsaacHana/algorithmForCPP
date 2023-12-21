#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> S;
    queue<char> Q;
    int cnt = 1;

    while (n--)
    {
        int val;
        cin >> val;

        while (cnt <= val)
        {
            S.push(cnt++);
            Q.push('+');
        }
        if (S.top() != val)
        {
            cout << "NO";
            return 0;
        }
        S.pop();
        Q.push('-');
    }

    while (!Q.empty())
    {
        cout << Q.front() << "\n";
        Q.pop();
    }
}