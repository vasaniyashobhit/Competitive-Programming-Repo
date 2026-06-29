#include <iostream>
#include <iomanip>
using namespace std;

void solve()
{
    double x;
    cin >> x;
    double precision = 1e-6;

    double low = 0, high = x, ans = 0;
    while (low <= high)
    {
        double mid = (low + high) / 2;
        if (mid * mid <= x)
        {
            ans = max(ans, mid);
            low = mid + precision;
        }
        else
        {
            high = mid - precision;
        }
    }
    cout << setprecision(6) << fixed;
    cout << ans << endl;
}

int main()
{
    solve();
}