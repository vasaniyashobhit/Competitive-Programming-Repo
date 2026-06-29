#include <iostream>
#include <string>
#include <map>
using namespace std;

bool check(string a, string b, int mid, int n1, int n2)
{
    bool anss = false;
    string st = "";
    map<string, int> mp;
    for (int i = 0; i < mid; i++)
        st += a[i];
    mp[st] = 1;
    for (int i = mid; i < n1; i++)
    {
        st += a[i];
        st.erase(0, 1);
        mp[st] = 1;
    }

    string ss = "";
    for (int i = 0; i < mid; i++)
        ss += b[i];

    if (mp.find(ss) != mp.end())
        return true;

    for (int i = mid; i < n2; i++)
    {
        ss += b[i];
        ss.erase(0, 1);
        if (mp.find(ss) != mp.end())
        {
            anss = true;
            break;
        }
    }
    if (anss == true)
        return true;
    return false;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        string b;
        cin >> b;
        int n1 = a.size();
        int n2 = b.size();
        int l = 1, r = min(n1, n2), ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(a, b, mid, n1, n2))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (ans == -1)
        {
            cout << (n1 + n2) << endl;
            continue;
        }
        cout << (n1 + n2 - (2 * ans)) << endl;
    }

    return 0;
}