#include <iostream>
#include <vector>
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
        vector<long long> a(n);
        for (auto &it : a)
            cin >> it;
        sort(a.begin(), a.end());
        int lastno = a[0], lastsize = 1;
        int currno = 0, currsize = 0;
        int ans = 1;
        int k = 1;
        while (a[k] == a[k - 1])
        {
            lastsize++;
            ans++;
            // cout << "h1" << " ";
            k++;
        }
        currsize = lastsize;
        for (int i = k; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                currsize++;
                if ((currsize > lastsize) || (currno - 1 != lastno))
                {
                    ans++;
                    // cout << i << " " << currsize << " " << lastsize << " " << currno << " " << lastno << " ";
                }
            }
            else
            {
                lastsize = currsize;
                lastno = a[i - 1];
                currsize = 1;
                currno = a[i];

                if (currno - 1 != lastno)
                    ans++;
            }
        }
        // cout << endl;
        cout << ans << endl;
    }

    return 0;
}