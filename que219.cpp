#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int>a(n);
        for(int &it:a) cin>>it;

        vector<int> hash(n,0);
        int p = -1;
        hash[0] = -1;
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]){
                p = i-1;
                hash[i] = i-1;
            }
            else{
                hash[i] = p;
            }
        }
        
        int q; cin>>q;
        while(q--){
            int l,r; cin>>l>>r;
            if(hash[r-1]+1<l){
                cout<<-1<<" "<<-1<<endl;
            }
            else{
                cout<<hash[r-1]+1<<" "<<r<<endl;
            }
        }
    }

    return 0;
}