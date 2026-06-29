#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,q; cin>>n>>q;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        vector<int> b(q);
        for(int &it:b) cin>>it;
        
        int min = 32;
        for(int i=0;i<q;i++){
            if(b[i]<min){
                for(int j=0;j<n;j++){
                    if((a[j]%(1<<b[i]))==0) a[j] += 1<<(b[i]-1);
                }
                min = b[i];
            }
        }
        for(auto it:a) cout<<it<<" ";
        cout<<endl;

    }

    return 0;
}