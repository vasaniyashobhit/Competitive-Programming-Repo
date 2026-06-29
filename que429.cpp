#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string a; cin>>a;

        if(n==1){
            cout<<1<<endl;
            continue; 
        }

        int cnt = 0;  // count of 0;
        int ans = 0;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(a[i]=='1'){
                cnt--;
                if(cnt>=0) ans += cnt/3;
                if(cnt%3!=0 && cnt>=0) ans++;
                cnt = 0;
                ind = i;
                break;
            }
            else cnt++;
        }
        
        if(ind==-1){
            ans = cnt/3;
            if(cnt%3!=0) ans++;
            cout<<ans<<endl;
            continue;
        }

        for(int i=ind+1;i<n;i++){
            if(a[i]=='1'){
                cnt -= 2;
                if(cnt>=0) ans += cnt/3;
                if(cnt%3!=0 && cnt>=0) ans++;
                cnt = 0;
            }
            else cnt++;
        }
        if(cnt>0){
            cnt--;
            ans += cnt/3;
            if(cnt%3!=0) ans++;
        }
        
        for(int i=0;i<n;i++){
            if(a[i]=='1') ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}