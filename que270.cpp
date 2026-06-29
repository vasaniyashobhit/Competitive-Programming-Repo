#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> p(n);
        for(int &it:p) cin>>it;
        string x; cin>>x;

        int indl,inds;
        for(int i=0;i<n;i++){
            if(p[i]==1) inds=i;
            if(p[i]==n) indl=i;
        }

        if(x[inds]=='1' || x[indl]=='1' || x[0]=='1' || x[n-1]=='1'){
            cout<<-1<<endl;
        }
        else{
            cout<<5<<endl;
            
            cout<<1<<" "<<inds+1<<endl;
            cout<<inds+1<<" "<<n<<endl;
            
            cout<<1<<" "<<indl+1<<endl;
            cout<<indl+1<<" "<<n<<endl;

            if(indl>inds) cout<<inds+1<<" "<<indl+1<<endl;
            else cout<<indl+1<<" "<<inds+1<<endl;
        }
    }

    return 0;
}