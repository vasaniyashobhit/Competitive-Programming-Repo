#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    if (a == b)
        cout << "infinity" << endl;
    else if (a < b)
        cout << 0 << endl;
    else
    {
        long long count = 0;
        long long x = a - b;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if (i * i == x)
                {
                    if (i > b)
                        count++;
                }
                else
                {
                    if (i > b)
                        count++;
                    if (x / i > b)
                        count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}