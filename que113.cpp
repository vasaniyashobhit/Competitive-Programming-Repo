#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> checker(1e5 + 1, 0);

void factinsert(long long k)
{
    for (long long d = 2; d * d <= k; d++)
    {
        if (k % d == 0)
            checker[d]++;
        while (k % d == 0)
            k /= d;
    }
    if (k > 1)
        checker[k]++;
    return;
}

void factdelete(long long k)
{
    for (long long d = 2; d * d <= k; d++)
    {
        if (k % d == 0)
            checker[d]--;
        while (k % d == 0)
            k /= d;
    }
    if (k > 1)
        checker[k]--;
    return;
}

int check(long long k)
{
    for (long long d = 2; d * d <= k; d++)
    {
        if (k % d == 0)
        {
            if (checker[d] != 0)
                return d;
        }
        while (k % d == 0)
            k /= d;
    }
    if (k > 1)
    {
        if (checker[k] != 0)
            return k;
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> status(1e5 + 1, 0);
    while (m--)
    {
        string s;
        cin >> s;
        string numb;
        cin >> numb;
        // cout << numb << endl;
        int num = stoi(numb);
        if (s[0] == '+')
        {
            if (status[num] == 1)
                cout << "Already on" << endl;
            else
            {
                int ch = 0;
                ch = check(num);
                if (ch == 0)
                {
                    status[num] = 1;
                    cout << "Success" << endl;
                    factinsert(num);
                }
                else
                {
                    cout << ("Conflict with " + to_string(ch)) << endl;
                }
            }
        }
        else
        {
            if (status[num] == 0)
                cout << "Already off" << endl;
            else
            {
                cout << "Success" << endl;
                status[num] = 0;
                factdelete(num);
            }
        }
    }
    return 0;
}