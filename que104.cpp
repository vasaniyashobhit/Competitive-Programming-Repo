#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, p;
    cin >> n >> p;
    vector<long long> a(n);
    for (long long &it : a)
        cin >> it;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }

    if (sum == p)
    {
        cout << 0 << " " << n << endl;
    }
    else
    {
        long long ans = n * (p / sum);
        p = p % sum;
        long long tot = 0;
        long long l = 0, r = 0;
        long long seg = 0;
        long long ind = 0;
        while (r < n)
        {
            tot += a[r];
            while (tot > sum - p)
            {
                tot -= a[l];
                l++;
            }
            if ((r - l + 1) > seg)
            {
                seg = r - l + 1;
                ind = r;
            }
            r++;
        }
        ind += 2;
        if (ind == n + 1)
        {
            ind = 1;
        }
        cout << ind << " " << (n - seg) << endl;
    }

    return 0;
}