#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    int k = 1; // 1->odda  2->oddb -3 for anything
    bool ans = true;
    for(int i=0;i<n;i++){
        if((n-i)%2==0){
            if(s[i]=='?') k = 3;
            else if(s[i]=='a') k = 2;
            else k = 1;
        }
        else{
            //cout<<i<<"-"<<k<<" ";
            if(s[i]=='a' && k==2) ans = false;
            if(s[i]=='b' && k==1) ans = false;
        }
        if(ans==false) break;
    }

    if(ans) cout<<"YES"<<endl;
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