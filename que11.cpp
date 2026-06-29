#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool one = false;
        bool nn = false;
        bool n1 = false;

        if (s[0] == 'A')
        {
            one = true;
        }
        if (s[n - 1] == 'A')
        {
            nn = true;
        }
        if (s[n - 2] == 'A')
        {
            n1 = true;
        }

        if (one == false && nn == false)
        {
            cout << "Bob" << endl;
        }
        else if (one == true && nn == true)
        {
            cout << "Alice" << endl;
        }
        else if (nn == true && one == false)
        {
            if (n1 == true)
            {
                cout << "Alice" << endl;
            }
            else
                cout << "Bob" << endl;
        }
        else
        {
            bool ans = true;
            for (int i = 1; i < n - 1; i++)
            {
                if (s[i] == 'B')
                {
                    ans = false;
                    break;
                }
            }
            if (ans == false)
                cout << "Bob" << endl;
            else
                cout << "Alice" << endl;
        }
    }
    return 0;
}