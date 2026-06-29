#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        vector<int> hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[a[i]]++;
        }
        bool k1=false;
        int it=-1;
        for(int i=1;i<=n;i++){
            if(hash[i]==0){
                k1=true;
                it = i;
            }
        }

        if(k1){
            int x,y=a[n-1],z=it;
            if(1!=y && 1!=z) x=1;
            else if(2!=y && 2!=z) x=2;
            else x=3;
            cout<<it<<" ";
            k--;
            while(k>=3){
                cout<<x<<" "<<y<<" "<<z<<" ";
                k -= 3;
            }
            if(k==2) cout<<x<<" "<<y<<endl;
            else if(k==1) cout<<x<<endl;
            else cout<<endl;
        }
        else{
            int x=a[n-3],y=a[n-2],z=a[n-1];
            while(k>=3){
                cout<<x<<" "<<y<<" "<<z<<" ";
                k -= 3;
            }
            if(k==2) cout<<x<<" "<<y<<endl;
            else if(k==1) cout<<x<<endl;
            else cout<<endl;
        }
    }

    return 0;
}