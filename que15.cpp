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
        bool k1 = false;
        bool k2 = false;
        int sum = 0;
        bool ans = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                sum++;
            }
            else if (s[i] == ')')
            {
                sum--;
            }
            if (sum == 0 && i != 0 && i != (s.size() - 1))
            {
                // cout << "hello" << endl;
                ans = true;
                break;
            }
        }
        if (ans == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}