#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll t,h,u; cin>>t>>h>>u;
    ll sum = 0;
    
    // tu
    ll cnt1 = min(t,u);
    sum += 4*(cnt1);
    t -= cnt1;
    u -= cnt1;

    // tht
    ll cnt2 = min(t/2,h);
    sum += 7*(cnt2);
    t -= 2*(cnt2);
    h -= cnt2;
    
    // th
    ll cnt3 = min(t,h);
    sum += 5*(cnt3);
    t -= cnt3;
    h -= cnt3;
    
    //ttt
    ll cnt5 = t/3;
    sum += 7*(cnt5);
    t -= 3*(cnt5);

    //tt
    int cnt4 = t/2;
    sum += 5*(cnt4);
    if(t%2!=0) sum += 3;
    t = 0;
    
    //cout<<sum<<"-"<<t<<"-"<<h<<"-"<<u<<endl;

    sum += 3*h;
    sum += 3*u;
    sum += 3*t;

    cout<<sum<<endl;
    
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

