#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> c(n, 0);
        for (int &it : c)
            cin >> it;

        map<int, vector<int>> hash;
        vector<int> a;

        for (int i = 0; i < n; i++)
        {
            if (hash.find(c[i]) == hash.end())
            {
                a.push_back(c[i]);
                hash[c[i]].push_back(0);
                hash[c[i]].push_back(i + 1);
            }
            else
            {
                hash[c[i]].push_back(i + 1);
            }
        }

        // check
        // for (auto it : a)
        //     cout << it << " ";
        // cout << endl;
        // for (auto it : a)
        // {
        //     for (auto itt : hash[it])
        //         cout << itt << " ";
        //     cout << endl;
        // }
        // end check
        int minans = 1000000;
        for (int i = 0; i < a.size(); i++)
        {
            int maxdiff = 0, secdiff = 0;
            hash[a[i]].push_back(n + 1);
            for (int j = 1; j < hash[a[i]].size(); j++)
            {
                int diff = hash[a[i]][j] - hash[a[i]][j - 1] - 1;
                if (diff >= maxdiff)
                {
                    secdiff = maxdiff;
                    maxdiff = diff;
                }
                else if (diff >= secdiff)
                {
                    secdiff = diff;
                }
            }
            // cout << maxdiff << " " << secdiff << endl;
            maxdiff /= 2;
            if (minans > max(maxdiff, secdiff))
            {
                minans = max(maxdiff, secdiff);
            }
        }

        cout << minans << endl;
    }

    return 0;
}