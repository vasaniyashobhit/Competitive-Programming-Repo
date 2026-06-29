#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long num = 2;
        long long i = 1;
        long long ans = 0;
        while (i < n / 2)
        {
            ans += num;
            num *= 2;
            i++;
        }
        while (i < n)
        {
            ans -= num;
            num *= 2;
            i++;
        }
        ans += num;
        cout << ans << endl;
    }

    return 0;
}