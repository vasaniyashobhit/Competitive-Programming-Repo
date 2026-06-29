#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m,d; cin>>n>>m>>d;
        int cnt = d/m;
        cnt++;
        int ans = n/cnt;
        if(n%cnt!=0) ans++;
        cout<<ans<<endl;
    }

    return 0;
}