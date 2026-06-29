#include <iostream>
#include <string>
using namespace std;

int ask(int l, int r)
{
    string s = "? ";
    string k = to_string(l);
    s += k;
    s += ' ';
    string k1 = to_string(r);
    s += k1;
    cout << s << endl;
    int ind;
    cin >> ind;
    return ind;
}

int main()
{
    int n;
    cin >> n;
    int l = 1, r = n;
    int ans = -1;
    while (l <= r)
    {
        if (l == r)
        {
            ans = l;
            break;
        }
        int mid = ask(l, r);
        if (mid == l)
        {
            int mid1 = ask(l, (l + r) / 2);
            if (mid1 == mid)
            {
                r = (l + r) / 2;
            }
            else
            {
                l = ((l + r) / 2) + 1;
            }
            continue;
        }
        else if (mid == r)
        {
            int mid1 = ((l + r) / 2, r);
            if (mid1 == mid)
            {
                l = ((l + r) / 2);
            }
            else
            {
                r = ((l + r) / 2) - 1;
            }
            continue;
        }
        int secmax = ask(l, mid);

        if (secmax == mid)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "! " << ans << endl;

    return 0;
}