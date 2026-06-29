#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string ch = "hello";
    int k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ch[k])
        {
            k++;
        }
        if (k == 5)
            break;
    }
    if (k < 5)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}