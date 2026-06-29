#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long &it : a) cin >> it;

        vector<long long> pref(n);
        pref[0] = abs(a[0]);
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + abs(a[i]);
        }

        vector<long long> suff(n);
        suff[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suff[i] = suff[i + 1] + a[i];
        }

        long long maxans = 0;
        int ind=-1;
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] < 0) continue;
            long long ans = pref[i - 1] + suff[i + 1] - a[i];
            if(ans>maxans){
                ind = i;
            }
        }
    }
}