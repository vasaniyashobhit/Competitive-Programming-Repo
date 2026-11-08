#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> psquare;
const int lim = 1<<18;
int mp[lim];
int m;

void precompute(){
    for(int i=0;i*i<lim;i++){
        psquare.push_back(i*i);
    }

    m = psquare.size();
}

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    vector<int> pref(n,0);
    pref[0] = a[0];
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1]^a[i];
    }

    long long ans = 0;

    for(int i=n-1;i>=0;i--){
        ll cnt = n-i;
        mp[pref[i]]++;

        int prev = (i>0) ? pref[i-1] : 0;

        for(int j=0;j<m;j++){
            cnt -= mp[prev^psquare[j]];
        }

        ans += cnt;
    }

    for(int i=0;i<n;i++) mp[pref[i]] = 0;

    cout<<ans<<endl;
    
    return;

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}