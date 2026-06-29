#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int sum = x;
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            if (x & 1 << i)
            {
                count++;
            }
        }
        int onc = n - count;

        cout << sum << endl;
    }

    return 0;
}