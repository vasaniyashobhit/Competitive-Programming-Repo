#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string m1 = "-++-" , m2 = "+--+", m3 = "--0" , m4 = "++0";

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    if(s[0]=='0' || s.find("00")){
        cout<<-1<<endl;
        return;
    }

    bool thr = false;
    bool two = false;

    if(s.find(m1) || s.find(m2)) thr = true;

    if(thr==true) cout<<3<<endl;
    else if(two==true) cout<<2<<endl;
    else cout<<1<<endl;

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