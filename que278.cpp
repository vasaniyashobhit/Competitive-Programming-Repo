#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> a(n);
        for(auto &it:a) cin>>it;
        
        if(a[n-2]>a[n-1]){
            cout<<-1<<endl;
        }
        else if(a[n-2]<0 && a[n-1]<0){
            bool k = true;
            for(int i=0;i<n-1;i++){
                if(a[i+1]<a[i]){
                    k = false;
                    break;
                }
            }
            if(k==true) cout<<0<<endl;
            else cout<<-1<<endl;
        }
        else{
            cout<<n-2<<endl;
            for(int i=0;i<n-2;i++){
                cout<<i+1<<" "<<n-1<<" "<<n<<endl;
            }
        }

    }

    return 0;
}