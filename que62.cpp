#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &it : a)
        cin >> it;

    if (n < 3)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else if (n == 3)
    {
        if ((a[0] + a[1] + a[2]) == x)
        {
            cout << 1 << " " << 2 << " " << 3 << endl;
        }
        else
            cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    bool ans = false;
    int ind1, ind2, ind3;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(a[i]) != mp.end())
        {
            mp[a[i]]++;
        }
        else
        {
            mp[a[i]] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] < x)
            {
                int req = x - (a[i] + a[j]);
                if (mp.find(req) != mp.end())
                {
                    if (a[i] == a[j] && a[i] == req && mp[req] >= 3)
                    {
                        ans = true;
                        ind1 = i;
                        ind2 = j;
                        ind3 = req;
                        break;
                    }
                    else if (a[i] == req && mp[req] >= 2)
                    {
                        ans = true;
                        ind1 = i;
                        ind2 = j;
                        ind3 = req;
                        break;
                    }
                    else if (a[j] == req && mp[req] >= 2)
                    {
                        ans = true;
                        ind1 = i;
                        ind2 = j;
                        ind3 = req;
                        break;
                    }
                    else
                    {
                        ans = true;
                        ind1 = i;
                        ind2 = j;
                        ind3 = req;
                        break;
                    }
                }
            }
        }
        if (ans == true)
            break;
    }
    if (ans == false)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    ind1++;
    ind2++;
    int ind33;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == ind3)
        {
            ind33 = i + 1;
            break;
        }
    }
    cout << ind1 << " " << ind2 << " " << ind33 << endl;

    return 0;
}