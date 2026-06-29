#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

double ncr(double nn, double r)
{
    double num = 1;
    for (int i = 1; i <= nn; i++)
    {
        num *= i;
    }
    for (int i = 1; i <= r; i++)
    {
        num /= i;
    }
    for (int i = 1; i <= nn - r; i++)
    {
        num /= i;
    }
    return num;
}

int main()
{
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    double n = s1.size();
    double ve1 = 0;
    double ve2 = 0;
    double que = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '+')
            ve1++;
        if (s2[i] == '+')
            ve2++;
        if (s2[i] == '?')
            que++;
    }
    cout << fixed << setprecision(9);
    if ((ve2 > ve1) || (ve1 - ve2 > que))
    {
        double ans = 0;
        cout << ans << endl;
    }
    else
    {
        double req = ve1 - ve2;
        double ans = ncr(que, req) / pow(2, que);
        cout << ans << endl;
    }

    return 0;
}