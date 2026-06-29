#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (long long &it : v)
            cin >> it;

        long long oddmax = 0, evenmax = 0, oddsum = 0, evensum = 0;
        long long oddno = 0, evenno = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0)
            {
                evenno++;
                evensum += v[i];
                if (v[i] > evenmax)
                    evenmax = v[i];
            }
            else
            {
                oddno++;
                oddsum += v[i];
                if (v[i] > oddmax)
                    oddmax = v[i];
            }
        }

        if (oddno == 0)
        {
            cout << evenmax << endl;
        }
        else if (evenno == 0)
        {
            cout << oddmax << endl;
        }
        else
        {
            long long ans = 0;
            ans += evensum + oddsum - (oddno - 1);
            cout << ans << endl;
        }
    }
}