#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;


        long long cnt=0;
        vector<long long> ans;
        for(long long i=0;i<n;i++){
            if(a[i]%2==0){
                cnt++;
                ans.push_back(a[i]);
            }
            if(ans.size()>1) break;
        }

        if(cnt>=2){
            cout<<ans[0]<<" "<<ans[1]<<endl;
        }
        else{
            if(n>31){
                bool kk = false;
                for(int i=0;i<n;i++){
                    if(((a[i+1]%a[i])%2==0)){
                        cout<<a[i]<<" "<<a[i+1]<<endl;
                        kk = true;
                        break;
                    }
                }
                if(kk==false) cout<<-1<<endl;
            }
            else{
                bool k=false;
                for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                        if((a[j]%a[i])%2==0){
                            cout<<a[i]<<" "<<a[j]<<endl;
                            k=true;
                            break;
                        }
                    }
                    if(k==true) break;
                }
                if(k==false) cout<<-1<<endl;
            }
        }
    }

    return 0;
}