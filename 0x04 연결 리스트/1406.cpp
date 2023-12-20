#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string init;
    cin >> init;
    list<char> linkedList;
    for (auto c : init)
        linkedList.push_back(c);
    auto cursor = linkedList.end();
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        char cmd;
        cin >> cmd;
        if (cmd == 'L')
        {
            if (cursor != linkedList.begin())
                cursor--;
        }
        else if (cmd == 'D')
        {
            if (cursor != linkedList.end())
                cursor++;
        }
        else if (cmd == 'B')
        {
            if (cursor != linkedList.begin())
            {
                cursor--;
                cursor = linkedList.erase(cursor);
            }
        }
        else if (cmd == 'P')
        {
            char inserted;
            cin >> inserted;
            linkedList.insert(cursor, inserted);
        }
    }

    for (auto c : linkedList)
        cout << c;
}