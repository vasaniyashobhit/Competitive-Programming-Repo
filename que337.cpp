#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int &it:a) cin>>it;
    for(int &it:b) cin>>it;
    int ans=0;
    map<int,int> mp;
    int i=0,j=0;
    while(i<n && j<n){
        if(mp.find(a[i])!=mp.end()){
            i++;
        }
        else if(a[i]==b[j]){
            i++;
            j++;
        }
        else{
            ans++;
            mp[b[j]]=1;
            j++;
        }
    }
    cout<<ans<<endl;

    return 0;
}