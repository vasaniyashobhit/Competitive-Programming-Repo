#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long &it : a)
        cin >> it;
    map<long long, long long> seg;
    long long l = 0, r = 0;
    long long ans = 0;
    seg[a[0]] = 1;
    while (l < n && r < n)
    {
        while ((*(seg.rbegin())).first - (*(seg.begin())).first <= k)
        {
            r++;
            if ()
        }
    }

    return 0;
}