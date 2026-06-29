#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int t;
    cin >> t;
    set<long long> st;
    st.insert(2);
    for (long long i = 2; i <= 1e14; i *= 2)
    {
        st.insert(i);
    }
    while (t--)
    {
        long long n;
        cin >> n;
        if (st.find(n) == st.end())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}