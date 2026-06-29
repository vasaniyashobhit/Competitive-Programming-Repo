#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        vector<int> b;
        for(int i=0;i<n;i++){
            if(a[i]!=i) b.push_back(i);
        }

        int n2=b.size();
        int ans=0;
        for(int i=0;i<=31;i++){
            int ith=1;
            for(int j=0;j<n2;j++){
                ith = ith&((b[j]>>i)&1);
            }

            if(ith==1) ans = ans|(1<<i);
        }
        cout<<ans<<endl;
        
    }

    return 0;
}
