#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long m = (n * (n - 1)) / 2;
        vector<long long> b(m, 0);
        for (long long &it : b)
            cin >> it;
        vector<long long> a(n);
        sort(b.begin(), b.end());
        map<long long, long long> hash;
        vector<long long> no;
        for (int i = m; i >= 0; i--)
        {
            if (hash.find(b[i]) == hash.end())
            {
                hash[b[i]] = 1;
                no.push_back(b[i]);
            }
            else
            {
                hash[b[i]]++;
            }
        }

        vector<long long> ans;
        for (int i = 0; i < no.size(); i++)
        {
            while (hash[no[i]] > 0)
            {
                hash[no[i]] -= ans.size();
                ans.push_back(b[i]);
            }
        }
        for (auto it : ans)
            cout << it << " ";
    }

    return 0;
}