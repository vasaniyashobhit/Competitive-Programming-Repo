#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,x,m; cin>>n>>x>>m;
        vector<pair<int,int>> a(m,{0,0});
        for(pair<int,int> &it:a) cin>>it.first>>it.second;

        pair<int,int> ans = {-1,-1};
        for(int i=0;i<m;i++){
            if(a[i].first<=x && a[i].second>=x && ans.first==-1){
                ans.first = a[i].first;
                ans.second = a[i].second;
            }
            if(ans.first!=-1 && !(a[i].first>ans.second || a[i].second<ans.first)){
                ans.first = min(a[i].first,ans.first);
                ans.second = max(ans.second,a[i].second);
            }
        }
        //cout<<ans.first<<" "<<ans.second<<endl;

        if(ans.first==-1) cout<<1<<endl;
        else{
            cout<<(ans.second-ans.first+1)<<endl;
        }
    }

    return 0;
}