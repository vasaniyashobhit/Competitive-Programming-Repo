#include <bits/stdc++.h>
using namespace std;

void calc(long long a, vector<vector<long long>> &b)
{
    for (long long i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            long long cnt = 0;
            while (a % i == 0)
            {
                cnt++;
                a /= i;
            }
            b[i].push_back(cnt);
        }
    }
    if (a > 1)
    {
        b[a].push_back(1);
    }

    return;
}

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long &it : a)
        cin >> it;

    if(n==2){
        cout<<((a[0]*a[1])/__gcd(a[0],a[1]))<<endl;
        return 0;
    }

    vector<vector<long long>> b(200005);

    for (long long i = 0; i < n; i++)
    {
        calc(a[i], b);
    }

    long long ans = 1;

    for (long long i = 2; i < 200005; i++)
    {
        if (b[i].size() < n - 1)
            continue;
        sort(b[i].begin(), b[i].end());

        long long exp = 0;

        if(b[i].size()==n-1) exp = b[i][0];
        else exp = b[i][1];
        
        for(int j=0;j<exp;j++){
            ans *= i;
        }
    }

    cout << ans << endl;

    return 0;
}