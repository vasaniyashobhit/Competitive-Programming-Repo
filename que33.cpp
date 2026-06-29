#include <iostream>
#include <vector>
#include <set>
using namespace std;

int ask(int i)
{
    string y = "yes";
    string n = "no";
    string a;
    cout << i << endl;
    cin >> a;

    if (a == y)
        return 1;
    else
        return 0;
}

bool check(int d)
{
    int sizee = 11;
    if (d == 3)
    {
        sizee = 7;
    }
    else if (d == 5)
    {
        sizee = 4;
    }
    else if (d == 7)
    {
        sizee = 2;
    }
    vector<int> a = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    for (int i = 0; i < sizee; i++)
    {
        int k = ask(a[i]);
        if (k == 1)
        {
            return false;
        }
    }
    if (d == 3 || d == 5 || d == 7)
    {
        int k = max(ask(25), ask(49));
        if (k == 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    set<int> b = {2, 3, 5, 7};

    bool ans = true;
    int count = 0;
    int d;
    for (int i = 2; i <= 10; i++)
    {
        int k = ask(i);
        if (k == 1)
        {
            ans = false;
            count++;

            d = i;
        }
    }
    if ((b.find(d) != b.end()) && (count == 1))
    {
        ans = check(d);
    }
    if (ans == true)
    {
        cout << "prime" << endl;
    }
    else
        cout << "composite" << endl;

    return 0;
}