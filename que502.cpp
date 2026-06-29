#include <bits/stdc++.h>
using namespace std;

long long counter(long long cnt, string &u, long long x, long long s)
{
    int n = u.size();
    long long space = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (u[i] == 'A')
        {
            if (cnt > 0)
            {
                if (x > 0)
                {
                    cnt--;
                    x--;
                    ans++;
                    space += (s - 1);
                }
            }
            else
            {
                if (space > 0)
                {
                    space--;
                    ans++;
                }
            }
        }
        else if (u[i] == 'I')
        {
            if (x > 0)
            {
                x--;
                space += (s - 1);
                ans++;
            }
        }
        else
        {
            if (space > 0)
            {
                ans++;
                space--;
            }
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, s;
        cin >> n >> x >> s;
        string u;
        cin >> u;

        int cntu = 0;
        for (int i = 0; i < n; i++)
            if (u[i] == 'A')
                cntu++;

        long long l = 1, r = n;
        long long maxans = counter(0, u, x, s);
        //cout << counter(3, u, x, s) << endl;
        while (l <= r)
        {
            long long mid = l + ((r - l) / 2);
            long long cnt1 = counter(mid,u,x,s);
            long long cnt2 = counter(mid - 1,u,x,s);
            //cout<<mid<<"-"<<cnt1<<"-"<<cnt2<<endl;
            if (cnt1>cnt2)
            {
                maxans = cnt1;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << maxans << endl;
    }

    return 0;
}