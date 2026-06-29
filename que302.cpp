#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,l,r; cin>>n>>l>>r;
        vector<long long> a;

        bool ans=true;
        for(int i=1;i<=n;i++){
            long long temp = ((l+i-1)/i)*i;
            if(temp<=r){
                a.push_back(temp);
            }
            else{
                ans=false;
                break;
            }
        }
        if(ans){
            cout<<"YES"<<endl;
            for(auto it:a) cout<<it<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }

    return 0;
}