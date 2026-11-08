#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    string a; cin>>a;
    string b; cin>>b;

    int sum1=0,sum2=0;

    bool ans = true;
    for(int i=0;i<n;i++){
        int x,y;
        x = (a[i]==')') ? -1 : 1;
        y = (b[i]==')') ? -1 : 1;

        if(sum1==sum2 || x==y){
            sum1 += x;
            sum2 += y;
        }
        else{
            sum1 += min(x,y);
            sum2 += max(x,y);
        }

        if(sum1<0 || sum2<0) ans=false;
        if(sum1<sum2) swap(sum1,sum2);
    }
    if((sum1!=0) || (sum2|=0)) ans = false;

    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}