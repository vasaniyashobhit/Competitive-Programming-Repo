#include <iostream>
#include <vector>
using namespace std;

vector<int> a(1000001, 1);
void sieve()
{
    int maxn = 1000000;
    a[0] = a[1] = 0;
    for (int i = 2; i * i <= maxn; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j <= maxn; j = j + i)
            {
                a[j] = 0;
            }
        }
    }
}

vector<int> suff(1000001, 0);
void suffixprefix()
{
    // suffix
    int last = -1;
    for (int i = 1000000; i > 0; i--)
    {
        if (a[i])
        {
            last = i;
        }
        else
        {
            suff[i] = last;
        }
    }
}

int main()
{
    sieve();
    suffixprefix();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (vector<int> &it : mat)
    {
        for (int &itt : it)
            cin >> itt;
    }

    int minansrow = 1000000;
    for (int i = 0; i < n; i++)
    {
        int diff = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[mat[i][j]] == 0)
            {
                diff += suff[mat[i][j]] - mat[i][j];
            }
        }
        minansrow = min(minansrow, diff);
    }

    int minanscol = 1000000;
    for (int j = 0; j < m; j++)
    {
        int diff = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[mat[i][j]] == 0)
            {
                diff += suff[mat[i][j]] - mat[i][j];
            }
        }
        minanscol = min(minanscol, diff);
    }

    cout << min(minansrow, minanscol) << endl;

    return 0;
}