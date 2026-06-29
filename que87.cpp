#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            int i = 1;
            int j = n / 2 + 2;
            if (n == 1)
            {
                cout << 1 << endl;
                continue;
            }
            for (int k = 1; k <= n / 2; k++)
            {
                cout << i << " " << j << " ";
                i++;
                j++;
            }
            cout << i << endl;
        }
    }
}