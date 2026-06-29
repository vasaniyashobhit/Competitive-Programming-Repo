#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n)
{

    // creation of boolean array
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {

            // marking as false
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    vector<int> res;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            res.push_back(p);
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p = sieve(n);
        vector<int> ans(n + 1, -1);
        int si = p.size();
        for (int i = si - 1; i >= 0; i--)
        {
            int num = p[i];
            int j = 2 * num, l = num;
            while (j <= n)
            {
                if (ans[j] == -1)
                {
                    ans[j] = l;
                    l = j;
                }
                j += num;
            }
            ans[num] = l;
        }
        ans[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}