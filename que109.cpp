#include <iostream>
#include <vector>
using namespace std;

int N = 1e6 + 1;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
        cin >> it;

    vector<int> hash(N, 0);
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        int count = 0;
        for (int j = i; j < N; j += i)
            count += hash[j];
        if (count > 1)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}