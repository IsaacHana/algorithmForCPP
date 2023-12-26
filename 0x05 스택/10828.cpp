#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int N;
    cin >> N;

    while (N--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            int val;
            cin >> val;
            S.push(val);
        }
        else if (cmd == "pop")
        {
            if (!S.empty())
            {
                cout << S.top() << "\n";
                S.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else if (cmd == "top")
        {
            if (!S.empty())
            {
                cout << S.top() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        else if (cmd == "size")
        {
            cout << S.size() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << S.empty() << "\n";
        }
    }
}