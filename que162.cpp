#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long &it : a)
        cin >> it;

    map<long long, long long> mp;
    vector<pair<long long, long long>> ans;
    // cout << "hello1" << endl;
    long long k = 0, pr = 1;
    for (long long i = 0; i < n; i++)
    {

        if (mp.find(a[i]) != mp.end())
        {
            ans.push_back({pr, i + 1});
            mp.clear();
            k++;
            pr = i + 2;
        }
        else
            mp[a[i]] = 1;
        // cout << "h1" << " ";
    }
    // cout << "hello2" << endl;
    if (k == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    ans.back().second = n;
    cout << k << endl;
    for (auto it : ans)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}