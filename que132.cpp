#include <iostream>
#include <vector>
#include <math.h>
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
        for (long long &it : a)
            cin >> it;
        long long ones = 0, zr = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                zr++;
            if (a[i] == 1)
                ones++;
        }
        long long ans = ones * (pow(2, zr));
        cout << ans << endl;
    }

    return 0;
}