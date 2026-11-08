#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s; cin>>s;
    string t; cin>>t;

    int n = s.size();
    int m = t.size();

    vector<int> hash(28,0);
    for(int i=0;i<m;i++){
        hash[t[i]-'a']++;
    }
    bool k = true;
    for(int i=0;i<n;i++){
        hash[s[i]-'a']--;
        if(hash[s[i]-'a']==-1) k = false;
    }

    if(k==false){
        cout<<"Impossible"<<endl;
        return;
    }

    string ans = "";
    int i=0,j=0;
    while(true){
        if(i==n && j==27) break;
        
        if(i==n){
            for(int it=0;it<hash[j];it++) ans += ('a'+j);
            j++;
        }
        else if(j==27){
            ans += s[i];
            i++;
        }
        else if(s[i]<=('a'+j)){
            ans += s[i];
            i++;
        }
        else{
            for(int it=0;it<hash[j];it++) ans += ('a'+j);
            j++;
        }

    }
    cout<<ans<<endl;
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