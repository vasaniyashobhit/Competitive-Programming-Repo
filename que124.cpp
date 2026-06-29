#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int countab = 0;
        int countba = 0;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            if (s[i - 1] == 'a' && s[i] == 'b')
            {
                countab++;
            }
            else if (s[i - 1] == 'b' && s[i] == 'a')
            {
                countba++;
            }
        }

        if (countab == countba)
        {
            cout << s << endl;
        }
        else if (countab > countba)
        {
            if (s[n - 1] == 'b')
            {
                s[n - 1] = 'a';
            }
            else if (s[0] == 'a')
            {
                s[0] = 'b';
            }
            cout << s << endl;
        }
        else
        { // ba > ab
            if (s[0] == 'b')
            {
                s[0] = 'a';
            }
            else if (s[n - 1] == 'a')
            {
                s[n - 1] = 'b';
            }
            cout << s << endl;
        }
    }

    return 0;
}