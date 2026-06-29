#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (vector<int> &it : a)
        {
            for (int &itt : it)
                cin >> itt;
        }
        int sum = 0, cnt = 0;
        int sm = abs(a[0][0]);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                sum += abs(a[i][j]);
                sm = min(sm, abs(a[i][j]));
                if (a[i][j] < 0)
                    cnt++;
            }
        }
        if (cnt % 2 != 0)
            sum -= 2 * sm;
        cout << sum << endl;
    }

    return 0;
}