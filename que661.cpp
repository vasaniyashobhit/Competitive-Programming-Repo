#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXV = 1000000;
int spf[MAXV + 1];

vector<int> giveoddPrimeFactor(ll num){
    vector<int> oddprimefactors;
    while(num>1){
        int p = spf[num], cnt = 0;
        while(num%p==0){
            num /= p;
            cnt++;
        }
        if(cnt&1) oddprimefactors.push_back(p);
    }
    return oddprimefactors;
}

void solve() {
    ll n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    vector<vector<int>> ker(n);
    for (int i = 0; i < n; i++) ker[i] = giveoddPrimeFactor(a[i]);

    map<vector<int>,int> mp;
    for(int i=0;i<n;i++){
        if(mp.find(ker[i])==mp.end()) mp[ker[i]]=1;
        else mp[ker[i]]++;
    }

    set<int> st;
    ll count = 0;
    for(int i=0;i<n;i++){
        vector<int> p = ker[i];
        for(auto it:p){
            if(st.find(it)==st.end()) st.insert(it);
            else st.erase(it);
        }
        
        if(st.size()>7) continue;
        
        auto it = vector<int>(st.begin(),st.end());
        if(mp.find(it)!=mp.end()) count+=mp[it];
    }

    cout<<count<<endl;

    return;

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= MAXV; i++)
    {
        if (spf[i] == 0)
        {                       
            for (int j = i; j <= MAXV; j += i) if (spf[j] == 0) spf[j] = i;
        }        
    }

    int t; cin >> t;
    while (t--) solve();

    return 0;
}