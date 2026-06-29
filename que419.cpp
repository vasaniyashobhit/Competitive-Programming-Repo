#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> ans(n+1);
        ans[n]=1;
        if(n%2==0) ans[1] = n;
        else ans[1] = n-1;
        for(int i=2;i<=n-1;i++){
            ans[i] = i^1;
        }

        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}