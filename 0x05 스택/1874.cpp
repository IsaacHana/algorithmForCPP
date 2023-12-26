#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    queue<char> Q;
    int n, cur = 1;
    cin >> n;
    while (n--)
    {
        int val;
        cin >> val;

        while (cur <= val)
        {
            Q.push('+');
            S.push(cur++);
        }
        if (S.top() != val)
        {
            cout << "NO";
            return 0;
        }
        Q.push('-');
        S.pop();
    }

    while (!Q.empty())
    {
        cout << Q.front() << "\n";
        Q.pop();
    }
}