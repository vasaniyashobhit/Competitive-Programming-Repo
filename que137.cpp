#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &it : a)
        cin >> it;

    long long largest = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (a[i] > largest)
            largest = a[i];
    }
    cout << max(sum, 2 * largest) << endl;

    return 0;
}