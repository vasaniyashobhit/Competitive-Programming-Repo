#include <iostream>
using namespace std;

long long ask(long long a)
{
    cout << "?" << " " << 1 << " " << a << endl;
    long long sum;
    cin >> sum;
    return sum;
}

int main()
{
    long long n, t;
    cin >> n >> t;
    long long k;
    cin >> k;

    long long l = 1, r = n;
    long long ans = -1;

    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        long long ones = ask(mid);
        long long zeroes = mid - ones;

        if (zeroes > k)
        {
            r = mid - 1;
        }
        else if (zeroes < k)
        {
            l = mid + 1;
        }
        else
        {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << "! " << ans << endl;
}