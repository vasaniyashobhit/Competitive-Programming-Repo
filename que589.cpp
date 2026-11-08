#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(string &x, string &s){
    int n = x.size();
    int m = s.size();
    
    if(n<m) return false;
    
    for(int i=0;i<=n-m;i++){
        string temp = "";
        for(int j=i;j<i+m;j++) temp+=x[j];
        if(temp==s) return true;
    }
    return false;
}

void solve() {
    int n,m; cin>>n>>m;
    string x; cin>>x;
    string s; cin>>s;
    bool k = false;
    int op = 0;
    while(n<=100){
        if(check(x,s)){
            k=true;
            break;
        }
        op++;
        n*=2;
        x += x;
    }

    if(k) cout<<op<<endl;
    else cout<<-1<<endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}