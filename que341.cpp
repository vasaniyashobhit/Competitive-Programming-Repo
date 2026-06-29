#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int l,a,b; cin>>l>>a>>b;
        int ans=a;
        for(int i=0;i<=l;i++){
            ans = max(ans,(a+i*b)%l);
        }
        cout<<ans<<endl;
    }

    return 0;
}