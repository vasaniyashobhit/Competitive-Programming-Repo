#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,x; cin>>n>>x;
        if(x>n){
            cout<<-1<<endl;
            continue;
        }
        else if(n==x){
            cout<<x<<endl;
            continue;
        }

        bool k = true;
        for(int i=0;i<63;i++){
            if(((x>>i)&1)==1 && ((n>>i)&1)==0){
                k = false;
                break;
            }
        }
        if(k==false){
            cout<<-1<<endl;
            continue;
        }

        long long largind = -1;
        long long minind = 1000;
        for(long long i=0;i<63;i++){
            if((((n>>i)&1)==1) && (((x>>i)&1)==0)){
                largind = i;
            }
            if((((n>>i)&1)==1) && (((x>>i)&1)==1))
            minind = min(i,minind);
        }
        
        if(minind<largind){
            cout<<-1<<endl;
            continue;
        }
        

        if(((n>>(largind+1))&1)==1){
            // cout<<"hello"<<endl;
            cout<<-1<<endl;
            continue;
        }

        long long ans=0;
        for(int i=largind+1;i<63;i++){
            if(((n>>i)&1)==1) ans = ans|(1ll<<i);
        }
        ans += (1ll<<largind) + (1ll<<largind);
        
        cout<<ans<<endl;
    }
}