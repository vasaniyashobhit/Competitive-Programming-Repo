#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int x,y; cin>>x>>y;
    int s = x+y;
    int newx = 0;

    for(int i=30;i>=0;i--){
        if((s>>i)&1){
            if(newx+(1<<i) <= x) newx += (1<<i);
        }
    }

    cout<<x+y<<" "<<x-newx<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}