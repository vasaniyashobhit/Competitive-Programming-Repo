#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        bool c1=false,c2=false;
        for(int i=0;i<n;i++){
            if(a[i]%10==5 || a[i]%10==0) c2=true;
            else c1=true;
        }

        if(c1==true && c2==true){
            cout<<"NO"<<endl;
            continue;
        }
        else if(c1==true){
            for(int i=0;i<n;i++){
                if(a[i]%10==1) a[i] += 15;
                if(a[i]%10==2) a[i] += 14;
                if(a[i]%10==3) a[i] += 3;
                if(a[i]%10==4) a[i] += 12;
                if(a[i]%10==7) a[i] += 19;
                if(a[i]%10==8) a[i] += 8;
                if(a[i]%10==9) a[i] += 17;
            }
            bool ans = true;
            for(int i=1;i<n;i++){
                if((abs(a[i]-a[i-1]))%20 != 0) ans = false;
            }
            if(ans) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            for(int i=0;i<n;i++) a[i]+=(a[i]%10);
            bool ans = true;
            for(int i=1;i<n;i++){
                if(a[i]!=a[0]) ans = false;
            }
            if(ans) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}