#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> d(n);
        for (long long &it : d)
        {
            cin >> it;
        }
        vector<vector<long long>> v(2, vector<long long>(n, 0));
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < 2; j++)
            {
                cin >> v[j][i];
            }
        }
        // for (auto it : v)
        // {
        //     for (auto itt : it)
        //     {
        //         cout << itt << " ";
        //     }
        //     cout << endl;
        // }
        vector<long long> maxh(n, 0);
        maxh[n - 1] = v[1][n - 1];
        long long maxi = maxh[n - 1];
        for (long long i = n - 1; i >= 0; i--)
        {
            if (v[1][i] <= maxi)
            {
                maxi = v[1][i];
            }
            maxh[i] = maxi;
        }

        vector<long long> minh(n, 0);
        minh[0] = v[0][0];
        long long mini = minh[0];
        for (long long i = 0; i < n; i++)
        {
            if (v[0][i] > mini)
            {
                mini = v[0][i];
            }
            minh[i] = mini;
        }
        // for (auto it : minh)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;
        // for (auto it : maxh)
        // {
        //     cout << it << " ";
        // }
        // cout << endl;
        vector<long long> ans(n, 0);
        long long currh = 0;
        bool anss = true;
        for (long long i = 0; i < n; i++)
        {
            if (d[i] == -1)
            {
                if (currh < maxh[i])
                {
                    d[i] = 1;
                }
                else
                {
                    d[i] = 0;
                }
            }
            if (d[i] == 1)
            {
                currh++;
            }
            ans[i] = d[i];
            if (maxh[i] < minh[i])
            {
                anss = false;
                break;
            }
            if (currh < minh[i])
            {
                anss = false;
                break;
            }
            if (currh > maxh[i])
            {
                anss = false;
                break;
            }
        }
        if (anss == false)
        {
            cout << -1 << endl;
        }
        else
        {
            for (auto it : ans)
            {
                cout << it << " ";
            }
            cout << endl;
        }
    }

    return 0;
}