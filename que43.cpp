#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int ask(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    int prod;
    cin >> prod;
    return prod;
}

int main()
{
    vector<int> a = {4, 8, 15, 16, 23, 42};
    vector<int> ans(6);
    map<int, pair<int, int>> mp;
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            int k = a[i] * a[j];
            mp[k] = {a[i], a[j]};
        }
    }
    // for (auto it : mp)
    // {
    //     cout << it.first << " " << it.second.first << " " << it.second.second << "  ";
    // }

    int prod1 = ask(1, 2);
    int prod2 = ask(2, 3);
    pair<int, int> p1 = mp[prod1];
    pair<int, int> p2 = mp[prod2];
    if ((p1.first == p2.first) || (p1.first == p2.second))
    {
        ans[1] = p1.first;
        ans[0] = p1.second;
        if (p1.first == p2.first)
        {
            ans[2] = p2.second;
        }
        else
            ans[2] = p2.first;
    }
    else
    {
        ans[1] = p1.second;
        ans[0] = p1.first;
        if (p1.second == p2.first)
        {
            ans[2] = p2.second;
        }
        else
            ans[2] = p2.first;
    }

    // second

    int prod3 = ask(4, 5);
    int prod4 = ask(5, 6);
    pair<int, int> p3 = mp[prod3];
    pair<int, int> p4 = mp[prod4];
    if ((p3.first == p4.first) || (p3.first == p4.second))
    {
        ans[4] = p3.first;
        ans[3] = p3.second;
        if (p3.first == p4.first)
        {
            ans[5] = p4.second;
        }
        else
            ans[5] = p4.first;
    }
    else
    {
        ans[4] = p3.second;
        ans[3] = p3.first;
        if (p3.second == p4.first)
        {
            ans[5] = p4.second;
        }
        else
            ans[5] = p4.first;
    }

    cout << "! ";
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    return 0;
}