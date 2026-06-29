#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &it : a)
        cin >> it;
    auto itr = lower_bound(a.begin(), a.end(), 4);
    cout << *(--itr) << endl;

    return 0;
}