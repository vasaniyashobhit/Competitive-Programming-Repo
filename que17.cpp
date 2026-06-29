#include <iostream>
#include <string>
#include <math.h>
using namespace std;

long long power(long long a, long long b)
{
    long long ans = a;
    long long r = 1;
    while (b > 1)
    {
        if (b % 2 == 0)
        {
            ans = ans * ans;
            b /= 2;
        }
        else
        {
            r *= ans;
            b--;
        }
    }
    ans *= r;
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = stoi(s);
        bool ans = false;
        int aa, bb;
        for (int a = 0; a * a <= n; a++)
        {
            for (int b = 0; b * b <= n; b++)
            {
                if (power((a + b), 2) == n)
                {
                    ans = true;
                    aa = a;
                    bb = b;
                    break;
                }
            }
            if (ans == true)
            {
                break;
            }
        }
        if (ans == true)
        {
            cout << aa << " " << bb << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}