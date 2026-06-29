#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a(n, {0, 0});
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    set<long long> dep;
    map<long long, long long> mp; // dep,room
    vector<long long> ans2;
    long long ans1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (dep.empty())
        {
            mp[a[i].second] = 1;
            ans2.push_back(1);
            dep.insert(a[i].second);
        }
        else if ((*(dep.begin())) < a[i].first)
        {
            ans2.push_back(mp[*dep.begin()]);
            dep.erase(*dep.begin());
            mp[a[i].second] = dep.size() + 1;
        }
    }
}