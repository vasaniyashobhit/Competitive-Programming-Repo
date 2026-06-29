#include <iostream>
#include <set>
#include <vector>
using namespace std;

void balance(multiset<int> &s1, multiset<int> &s2, int n, int k)
{
    if (k % 2 == 0)
    {
        while (s1.size() > s2.size())
        {
            int out = *(s1.rbegin());
            s1.erase(out);
            s2.insert(out);
        }

        while (s2.size() > s1.size())
        {
            int out = *(s2.begin());
            s2.erase(out);
            s1.insert(out);
        }
    }
    else
    {
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &it : v)
        cin >> it;
    multiset<int> s1;
    multiset<int> s2;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (s1.empty() || v[i] <= *(s1.rbegin()))
        {
            s1.insert(v[i]);
        }
        else
            s2.insert(v[i]);
        balance(s1, s2, n, k);

        if (i >= k)
        {
            int out = v[i - k];
            if (out <= *(s1.rbegin()))
                s1.erase(out);
            else
                s2.erase(out);
            balance(s1, s2, n, k);
        }

        if (i >= k - 1)
        {
            if (k % 2 == 1)
                ans.push_back(*(s1.rbegin()));
            else
            {
                ans.push_back(((double)*(s1.rbegin()) + (double)*(s2.begin())) / 2.0);
            }
        }
    }
    for (auto it : ans)
        cout << it << " ";
    cout << endl;

    return 0;
}