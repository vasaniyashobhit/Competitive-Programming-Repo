#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int ask (int a,int b){
    string asking = "? " + to_string(a) + " " + to_string(b);
    cout<<asking<<endl;
    cout.flush();
    int ans; cin>>ans;
    return ans;
}

void solve() {
    int l=1,r=1000;
    while(r-l>1){
        int m1 = l + (r-l)/3;
        int m2 = l + 2*(r-l)/3;

        int result = ask(m1,m2);

        if(result == (m1+1)*(m2+1)){
            r = m1;
        }
        else if(result == m1*(m2+1)){
            l = m1;
            r = m2;
        }
        else{
            l = m2;
        }
    }

    cout<<"! "<<r<<endl;
    cout.flush();
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