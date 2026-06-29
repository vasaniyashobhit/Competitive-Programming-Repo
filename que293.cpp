#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long ind1 = 0;
        long long ind2 = -1;
        for(int i=1;i<n;i++){
            if(a[i]!=a[0]){
                ind2 = i;
                break;
            }
        }

        if(ind2==-1){
            cout<<"NO"<<endl;
            continue;
        }
        else cout<<"YES"<<endl;
        cout<<(ind1+1)<<" "<<(ind2+1)<<endl;
        for(int i=1;i<n;i++){
            if(i==ind2) continue;
            
            if(a[i]==a[0]) cout<<(i+1)<<" "<<(ind2+1)<<endl;
            else cout<<1<<" "<<(i+1)<<endl;
        }
    }

    return 0;
}