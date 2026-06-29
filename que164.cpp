#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int q;
        cin >> q;
        long long n1 = 1, n2 = 1;
        bool bb = true, aa = true;
        while (q--)
        {
            long long a, b;
            string s;
            cin >> a >> b >> s;
            long long ss = s.size();
            if (a == 1)
                n1 += (b * ss);
            else
                n2 += (b * ss);
            for (long long i = 0; i < ss; i++)
            {
                if (s[i] != 'a')
                {
                    if (a == 1)
                        aa = false;
                    else
                        bb = false;
                }
            }

            if (bb == false)
                cout << "YES" << endl;
            else
            {
                if (aa == true && n1 < n2)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        }
    }

    return 0;
}