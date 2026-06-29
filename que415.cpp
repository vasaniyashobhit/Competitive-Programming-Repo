#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        int ans=0;
        int cnt=0;
        int i=0;
        for(;i<n;i++){
            if(a[i]==0) break;
            cnt++;
        }
        ans += cnt/3;
        if(cnt%3!=0) ans++;
        cnt = 0;
        for(;i<n;i++){
            if(a[i]==0){
                ans += cnt/3;
                cnt = 0;
            }
            else cnt++;
        }
        ans+=cnt/3;
        cout<<ans<<endl;
    }

    return 0;
}