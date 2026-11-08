#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void helper(int ind,vector<ll> &a, vector<int> &visited, vector<ll> &lcms, string &s){

    string newstring = "";
    newstring += s[ind];
    int i = a[ind];
    while(i!=ind){
        newstring += s[i];
        visited[i]=1;
        i = a[i];
    }

    int len = newstring.size();
    for(int i=1;i<=len;i++){
        bool k = true;
        for(int j=0;j<len;j++){
            if(newstring[j] != newstring[(j+i)%len]) k = false;
        }

        if(k==true){
            lcms.push_back(i);
            break;
        }
    }

    return;
}

void solve() {
    ll n; cin>>n;
    string s; cin>>s;
    vector<ll> a(n);
    for(ll &it:a) cin>>it;
    for(int i=0;i<n;i++) a[i]--;
    // for(auto it:a) cout<<it<<" ";
    // cout<<endl;

    
    vector<int> visited(n,0);
    vector<ll> lcms;
    for(int i=0;i<n;i++){
        if(visited[i]==0) helper(i,a,visited,lcms,s);

    }

    ll lcm = lcms[0];
    for(int i=0;i<lcms.size();i++){
        lcm = (lcm*lcms[i])/__gcd(lcm,lcms[i]);
    }
    cout<<lcm<<endl;

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}