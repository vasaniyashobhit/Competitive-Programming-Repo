#include <iostream>
#include <vector>
#include <map>
#include <set>
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

        set<long long> s1;
        set<long long> s2;
        s1.insert(a[0]);

        bool k = true;
        long long count = 1;
        for (long long i = 1; i < n; i++)
        {
            if (k == true)
            {
                if (s1.find(a[i]) == s1.end())
                {
                    s2.insert(a[i]);
                }
                else
                {
                    s2.insert(a[i]);
                    s1.erase(a[i]);
                }
                if (s1.empty())
                {
                    count++;
                    k = false;
                }
            }
            else
            {
                if (s2.find(a[i]) == s2.end())
                {
                    s1.insert(a[i]);
                }
                else
                {
                    s1.insert(a[i]);
                    s2.erase(a[i]);
                }
                if (s2.empty())
                {
                    count++;
                    k = true;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}