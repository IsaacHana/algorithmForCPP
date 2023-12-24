#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    stack<int> S;
    queue<string> Q;

    int cnt = 1;
    while (n--)
    {
        int val;
        cin >> val;

        while (cnt <= val)
        {
            Q.push("+");
            S.push(cnt++);
        }
        if (S.top() != val)
        {
            cout << "NO";
            return 0;
        }

        Q.push("-");
        S.pop();
    }

    while (!Q.empty())
    {
        cout << Q.front() << "\n";
        Q.pop();
    }
}