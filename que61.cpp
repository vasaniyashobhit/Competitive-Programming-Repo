#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &it : a)
            cin >> it;

        pair<int, int> seg;
        int maxpeak = 0;
        int peak = 0;

        for (int i = 1; i <= k - 2; i++)
        {
            if ((a[i] > a[i - 1]) && (a[i] > a[i + 1]))
            {
                peak++;
            }
        }

        // cout << peak << endl;
        maxpeak = peak;
        seg = {0, k - 1};
        int l = 1, r = k;
        while (r < n)
        {
            if ((a[l] > a[l - 1]) && (a[l] > a[l + 1]))
            {
                peak--;
            }
            if ((a[r - 1] > a[r]) && (a[r - 1] > a[r - 2]))
            {
                peak++;
            }

            if (peak > maxpeak)
            {
                seg.first = l;
                seg.second = r;
                maxpeak = peak;
            }
            l++, r++;
        }
        cout << (maxpeak + 1) << " " << (seg.first + 1) << endl;
    }

    return 0;
}