#include <iostream>
#include <set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long &it : a)
        cin >> it;
    multiset<long long> st;
    st.insert(a[0]);
    for (long long i = 1; i < n; i++)
    {
        auto it = upper_bound(st.begin(), st.end(), a[i]);
        if (it == st.end())
            st.insert(a[i]);
        else
        {
            st.erase(it);
            st.insert(a[i]);
        }
    }
    cout << st.size() << endl;

    return 0;
}