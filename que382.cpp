#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<long long>a(n);
    for(long long &it:a) cin>>it;

    vector<long long> b(n);
    for(int i=0;i<n;i++){
        b[i] = a[i]-i;
    }

    map<long long,long long> mp;
    for(int i=0;i<n;i++){
        if(mp.find(b[i])==mp.end()) mp[b[i]] = a[i];
        else mp[b[i]] += a[i];
    }

    long long maxans=0;
    for(int i=0;i<n;i++){
        maxans = max(mp[b[i]],maxans);
    }
    cout<<maxans<<endl;

    return 0;
}