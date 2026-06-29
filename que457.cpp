#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d; cin>>n>>d;
    vector<int> a(n);
    for(auto &it:a) cin>>it;

    d%=n;
    vector<int> ext(n,0);
    
    for(int i=0;i<n;i++){
        ext[i]=a[i];
    }

    vector<int> ans(n,0);
    for(int i=0;i<n-d;i++){
        ans[i] = a[i+d];
    }
    int j=0;
    for(int i=n-d;i<n;i++){
        ans[i] = ext[j++];
    }
    for(auto it:ans) cout<<it<<" ";

    return 0;
}