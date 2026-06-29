#include <iostream>
#include <vector>
using namespace std;

bool check(vector<long long> a, long long sum, long long k)
{
    long long n = a.size();
    long long sub = 0;
    for (int i = 0; i < n; i++)
    {
        if (k < 1 || a[i] > sum)
        {
            return false;
        }
        if (sub + a[i] > sum)
        {
            k--;
            sub = a[i];
        }
        else
        {
            sub += a[i];
        }
    }
    if (k >= 1)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long sum = 0;
    for (long long &it : a)
    {
        cin >> it;
        sum += it;
    }
    long long l = 0, r = sum;
    long long ans;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (check(a, mid, k))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}