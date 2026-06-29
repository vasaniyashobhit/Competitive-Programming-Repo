#include <bits/stdc++.h>
using namespace std;

int calc(int n, string &s, int cnt)
{
    vector<int> hash(27, 0);
    for (int i = 0; i < n; i++)
    {
        hash[s[i] - 'a']++;
    }

    vector<int> a;
    for (int i = 0; i < 27; i++)
    {
        if (hash[i] != 0)
            a.push_back(hash[i]);
    }

    int tot = (n / cnt);
   
    if(tot>=a.size()){
        int opless = 0;
        int opmore = 0;
        opless += cnt*(tot - a.size());
        for(int i=0;i<a.size();i++){
            if(a[i]>cnt){
                opmore += (a[i]-cnt);
            }
            else if(a[i]<cnt){
                opless += (cnt-a[i]);
            }
        }
        int op = min(opmore,opless) + abs(opmore-opless);
        return op;
    
    }
    else{
        // tot < a.size()
        sort(a.begin(),a.end());
        tot = a.size()-tot;
        int op = 0;
        for(int i=0;i<a.size();i++){
            if(tot>0){
                op += a[i];
                tot--;
            } 
            else op += abs(cnt-a[i]);
        }
        return op/2;
    }
    
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int minop = 1e5;
        int mincnt;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                int op1 = calc(n, s, i);
                if(op1<minop){
                    minop = op1;
                    mincnt = i;
                }

                int op2 = calc(n,s,n/i);
                if(op2<minop){
                    minop = op2;
                    mincnt = n/i;
                }
            }
        }
        cout <<mincnt<<" "<< minop << endl;
        
    }

    return 0;
}