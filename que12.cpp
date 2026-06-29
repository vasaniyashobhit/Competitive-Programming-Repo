#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 15000000;
vector<long long> s1(maxn, 1);
void sieve(vector<long long> &pref)
{
    s1[0] = s1[1] = 0;
    for (long long i = 2; i * i < maxn; i++)
    {
        if (s1[i] == 1)
        {
            for (long long j = i * i; j < maxn; j = j + i)
            {
                s1[j] = 0;
            }
        }
    }
    for (int i = 0; i < maxn; i++)
    {
        if (s1[i])
        {
            pref.push_back(i);
        }
    }
    for (int i = 1; i < pref.size(); i++)
    {
        pref[i] = pref[i] + pref[i - 1];
    }
}

int main()
{
    int t;
    cin >> t;
    vector<long long> pref;
    sieve(pref);
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long sum = 0;
        for (long long &it : a)
        {
            cin >> it;
            sum += it;
        }
        sort(a.begin(), a.end());
        long long count = 0;
        long long i = 0;
        long long siz = n - 1;
        while (sum < pref[siz] && i < n - 1)
        {
            count++;
            sum -= a[i++];
            siz--;
        }
        cout << count << endl;
    }
    return 0;
}