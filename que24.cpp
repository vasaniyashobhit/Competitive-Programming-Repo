#include <iostream>
#include <vector>
using namespace std;

bool check(vector<long long> time, long long t, long long pr, long long size)
{

    for (long long i = 0; i < size; i++)
    {
        pr -= t / time[i];
        if (pr <= 0)
        {
            break;
        }
    }
    if (pr <= 0)
        return true;
    else
        return false;
}

int main()
{
    long long n, t;
    cin >> n >> t;
    vector<long long> time(n);
    for (long long &it : time)
        cin >> it;
    long long l = 0, r = __LONG_LONG_MAX__;
    long long ans = -1;
    while (l <= r)
    {
        long long mid = (r + l) / 2;
        if (check(time, mid, t, n))
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