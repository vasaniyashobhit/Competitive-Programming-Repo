#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

double findSqrt(double x)
{
    // for 0 and 1, the square roots are themselves
    if (x < 2)
        return x;

    // considering the equation values
    double y = x;
    double z = (y + (x / y)) / 2;

    // as we want to get upto 5 decimal digits, the absolute
    // difference should not exceed 0.00001
    while (fabs(y - z) >= 0.00001)
    {
        y = z;
        z = (y + (x / y)) / 2;
    }
    return z;
}

double power(double x)
{
    return x * x;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double n;
        cin >> n;
        double p, q, r, s;
        cin >> p >> q >> r >> s;
        vector<double> a(n);
        for (double &it : a)
            cin >> it;

        double dist = findSqrt(power(abs(p - r)) + power(abs(q - s)));
        // cout << dist << endl;
        double sum = 0;
        for (double it : a)
            sum += it;

        if (dist == 0)
        {
            if (n > 2)
            {
                double largest = 0;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] > largest)
                    {
                        largest = a[i];
                    }
                }
                if ((sum >= 2 * largest))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            else if (n == 2)
            {
                if (a[0] == a[1])
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            else
                cout << "No" << endl;
        }
        else
        {
            double largest = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] > largest)
                {
                    largest = a[i];
                }
            }
            if (largest > dist + (sum - largest))
            {
                cout << "No" << endl;
                continue;
            }
            if ((sum >= dist))
                cout << "Yes" << endl;
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}