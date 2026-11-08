#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,k; cin>>n>>k;
    string s; cin>>s;

    int evenp=0,oddp = 0;
    for(int i=0;i<2*n-1;i++){
        if(s[i]=='1'){
            if(s[i+1]=='1'){
                if(i%2==0) evenp++;
                else oddp++;
            }
            else{
                if(i%2==0) oddp++;
                else evenp++;
            }
        }

    }

    if(s[2*n-1]=='1'){
        if(s[0]=='1') oddp++;
        else evenp++;
    }

    cout<<oddp<<" "<<evenp<<endl;

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