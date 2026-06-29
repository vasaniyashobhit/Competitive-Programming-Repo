#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m,a,b; cin>>n>>m>>a>>b;
        if(a>n) swap(a,n);
        if(b>m) swap(b,m);

        bool ans = true;
        int x = a;
        while(true){
            cout<<x<<" ";
            x = n%x;
            if(x==1) break;
            if(x==0){
                ans = false;
                break;
            }
        }
        cout<<endl;
        x = b;
        while(true){
            x = m%x;
            if(x==1) break;
            if(x==0){
                ans = false;
                break;
            }
        }
        if(ans==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;;
    }

    return 0;
}