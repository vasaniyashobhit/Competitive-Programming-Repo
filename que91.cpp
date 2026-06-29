#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '0')
            {
                count++;
                s[i] = '1';
            }
        }
        // cout << count << endl;

        if (count <= k)
        {
            cout << "ALICE" << endl;
        }
        else
        {
            if (k > n / 2)
            {
                cout << "ALICE" << endl;
            }
            else
            {
                cout << "BOB" << endl;
            }
        }
    }

    return 0;
}