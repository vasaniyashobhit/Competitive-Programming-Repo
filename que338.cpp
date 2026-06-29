#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    long long n = s.size();
    
    vector<long long> pref(n,0);
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1];
        if(s[i]=='v' && s[i-1]=='v') pref[i]++;
    }

    long long ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='o'){
            long long cnt = pref[i]*(pref[n-1]-pref[i]);
            ans += cnt;
        }
    }
    cout<<ans<<endl;

    return 0;
}