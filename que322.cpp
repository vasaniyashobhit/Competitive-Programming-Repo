#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        
        vector<int> ans;
        ans.push_back(a[0]);
        int prev = a[0];
        for(int i=1;i<n-1;i++){
            if(prev<a[i] && a[i]<a[i+1]) continue;
            else if(prev>a[i] && a[i]>a[i+1]) continue;
            prev = a[i];
            ans.push_back(a[i]);
        }
        ans.push_back(a[n-1]);
        cout<<ans.size()<<endl;;
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}