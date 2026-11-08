#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll a,b,c; cin>>a>>b>>c;
    ll n; cin>>n;

    vector<ll> v1;
    vector<ll> v2;
    vector<ll> v3;

    for(ll i=1;i*i<=a;i++){
        if(a%i==0){
            v1.push_back(i);
            v1.push_back(a/i);
        }
    }
    for(ll i=1;i*i<=b;i++){
        if(b%i==0){
            v2.push_back(i);
            v2.push_back(b/i);
        }
    }
    for(ll i=1;i*i<=c;i++){
        if(c%i==0){
            v3.push_back(i);
            v3.push_back(c/i);
        }
    }

    bool p = false;
    vector<ll> ans;
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            for(int k=0;k<v3.size();k++){
                if(v1[i]*v2[j]*v3[k]==n){
                    p = true;
                    ans.push_back(v1[i]);
                    ans.push_back(v2[j]);
                    ans.push_back(v3[k]);
                    break;
                }
            }
            if(p==true) break;
        }
        if(p==true) break;
    }

    if(p==false) cout<<-1<<endl;
    else cout<<ans[0]-1<<" "<<ans[1]-1<<" "<<ans[2]-1<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while (t--) solve();

    return 0;
}