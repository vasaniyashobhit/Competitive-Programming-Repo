#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s; cin>>s;
    int n = s.size();
    for(int i=1;i<n-1;i++){
        if(s[i]==s[i-1]){
            if(s[i-1]!='a' && s[i+1]!='a') s[i] = 'a';
            else if(s[i-1]!='b' && s[i+1]!='b') s[i] = 'b';
            else s[i] = 'c';
        }
    }
    if(s[n-1]==s[n-2]){
        if(s[n-2]=='a') s[n-1] = 'b';
        else s[n-1] = 'a';
    }
    cout<<s<<endl;
     
    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while (t--) solve();

    return 0;
}