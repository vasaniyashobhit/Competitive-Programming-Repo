#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a,b,c; cin>>a>>b>>c;
    string s; cin>>s;
    cout<<to_string(a+b+c)+" "+s<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while (t--) solve();

    return 0;
}