#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        vector<int> zrs;
        for(int i=0;i<n;i++){
            int x = a[i];
            int cnt = 0;
            while(x>0){
                int dig = x%10;
                if(dig==0){
                    cnt++;
                }
                else{
                    if(cnt>0) zrs.push_back(cnt);
                    break;
                }
                x/=10;
            }
        }

        sort(zrs.begin(),zrs.end());
        
        int mm = zrs.size();
        int ans = 0;
        for(int i=mm-2;i>=0;i-=2){
            ans += zrs[i];
        }
        //cout<<ans<<endl;

        for(int i=0;i<n;i++){
            while(a[i]%10==0) a[i]/=10;
            while(a[i]>0){
                ans++;
                a[i]/=10;
            }
            //cout<<ans<<" ";
        }
        ans--;

        if(ans>=m) cout<<"Sasha"<<endl;
        else cout<<"Anna"<<endl;
    }

    return 0;
}