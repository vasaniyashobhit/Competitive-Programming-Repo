#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long mov1 = 0, mov2 = 0, mov3 = 0, mov4 = 0;

        // 1st
        long long n1 = n;
        while (n1)
        {
            if (n1 % 10 == 5)
                break;
            else
                mov1++;
            n1 /= 10;
        }
        long long n2 = n;
        while (n2)
        {
            if ((n2 % 10 == 2 || n2 % 10 == 7) && mov2 > mov1)
                break;
            else
                mov2++;
            n2 /= 10;
        }
        long long ans1 = mov2 - 1;

        // 2nd
        long long n3 = n;
        while (n3)
        {
            if (n3 % 10 == 0)
                break;
            else
                mov3++;
            n3 /= 10;
        }
        long long n4 = n;
        while (n4)
        {
            if ((n4 % 10 == 0 || n4 % 10 == 5) && mov4 > mov3)
                break;
            else
                mov4++;
            n4 /= 10;
        }
        long long ans2 = mov4 - 1;
        cout << min(ans1, ans2) << endl;
    }

    return 0;
}