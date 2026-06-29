#include <iostream>
#include <vector>
using namespace std;

int ask(int a, int b)
{
    string s = "? ";
    s += ('0' + char(a));
    s += ' ';
    string k = to_string(b);
    s += k;
    cout << s << endl;
    int sum;
    cin >> sum;
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> pref(n, 0);
    for (int i = n; i >= 2; i--)
    {
        int sum = ask(1, i);
        pref[i - 1] = sum;
    }
    int sum = ask(2, n);
    pref[0] = pref[n - 1] - sum;
    cout << "! ";
    cout << pref[0] << " ";
    for (int i = 1; i < n; i++)
    {
        cout << (pref[i] - pref[i - 1]) << " ";
    }
    cout << endl;

    return 0;
}