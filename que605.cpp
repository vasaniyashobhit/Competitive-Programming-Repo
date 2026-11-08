#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void finddiffvals(vector<ll> &diffvals, ll n, ll m, ll k, vector<vector<ll>> &height, vector<string> &type){
    vector<vector<ll>> pref(n,vector<ll>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(type[i][j]=='1') pref[i][j] = 1;
            if(i>0) pref[i][j] += pref[i-1][j];
            if(j>0) pref[i][j] += pref[i][j-1];
            if(i>0 && j>0) pref[i][j] -= pref[i-1][j-1];
        }
    }

    for(int i=k-1;i<n;i++){
        for(int j=k-1;j<m;j++){
            int sum = pref[i][j];
            if(i-k>=0) sum -= pref[i-k][j];
            if(j-k>=0) sum -= pref[i][j-k];
            if(i-k>=0 && j-k>=0) sum += pref[i-k][j-k];

            int diff = abs((2*sum)-(k*k));
            diffvals.push_back(diff);
        }
    }

    return;
}

void solve() {
    ll n,m,k; cin>>n>>m>>k;
    vector<vector<ll>> height(n,vector<ll> (m));
    vector<string> type(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>height[i][j];
    }

    for(int i=0;i<n;i++){
        cin>>type[i];
    }

    ll initialdiff = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(type[i][j]=='1') initialdiff += height[i][j];
            else initialdiff -= height[i][j];
        }
    }
    initialdiff = abs(initialdiff);

    vector<ll> diffvals;
    finddiffvals(diffvals,n,m,k,height,type);

    ll gcd = 0;
    for(int i=0;i<diffvals.size();i++) gcd = __gcd(gcd,diffvals[i]);
    if(gcd==0){
        if(initialdiff == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }

    if(initialdiff % gcd == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}