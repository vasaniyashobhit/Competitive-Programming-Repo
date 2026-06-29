#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n % 2 == 0)
    {
        long long count = 0;
        long long i = 10;
        while (true)
        {
            count += n / i;
            if (i > n)
                break;
            i *= 10;
        }
        cout << count << endl;
    }
    else
    {
    }

    return 0;
}