#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,x; cin>>n>>x;

        if(n==2 && x==1){
            cout<<5<<endl;
            continue;
        }

        //cout<<n<<" "<<x<<endl;
        if(x==0){
            if(n%2==0) cout<<n<<endl;
            else if(n==1) cout<<-1<<endl;
            else cout<<(n-1+4)<<endl;
            continue;
        }

        if(n==1){
            cout<<x<<endl;
            continue;
        }


        if(x==1){
            if(n%2==0){
                cout<<(n-1+4)<<endl;
            }
            else{
                cout<<n<<endl;
            }
            continue;
        }

        long long set=0,ans=x;
        for(int i=0;i<=31;i++){
            if((x>>i)&1) set++;
        }
        ans += (n-set>0) ? n-set : 0 ;
        if((n-set)%2!=0 && (n-set)>0) ans++;
        cout<<ans<<endl;
    }

    return 0;
}