#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v;
        map<long long, long long> freq;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                v.push_back(i);
                freq[i] = 0;
                while (n % i == 0)
                {
                    n = n / i;
                    freq[i]++;
                }
            }
        }
        if (n > 1)
        {
            v.push_back(n);
            freq[n] = 1;
        }
        // for (int i = 0; i < v.size(); i++)
        // {
        //     cout << v[i] << " " << freq[v[i]] << endl;
        // }
        long long ans = 0;
        long long y = 1;
        while (true)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (freq[v[i]] > 0)
                {
                    y *= v[i];
                    freq[v[i]]--;
                }
            }
            if (y == 1)
                break;
            else
            {
                ans += y;
                y = 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}