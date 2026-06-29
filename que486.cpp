#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &it : a)
            cin >> it;
        sort(a.begin(), a.end());

        vector<int> b;
        vector<int> rep;
        b.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                rep.push_back(a[i]);
            }
            else
                b.push_back(a[i]);
        }


        int i = 0, l = b.size()-1, r = 0;
        int ans = -1;

        for (int j = 0; j <= n + 1; j++)
        {
            if (i > l || i >= b.size())
            {
                ans = j;
                break;
            }
            if (b[i] == j)
            {
                //cout<<"hello3 "<<j<<endl;
                i++;
                continue;
            }
            else
            {
                bool k = false;

                while (r < rep.size())
                {
                    if (rep[r] > 2 * j)
                    {
                        k = true;
                        r++;
                        //cout<<"hello2 "<<j<<endl;
                        break;
                    }
                    r++;
                }
                if (k == true)
                    continue;
                if (l >= 0 && l >= i && b[l] > 2 * j)
                {
                    k = true;
                    l--;
                    //cout<<"hello1 "<<j<<endl;
                }
                else
                {
                    ans = j;
                    break;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}