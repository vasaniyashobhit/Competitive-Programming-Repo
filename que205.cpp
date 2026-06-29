#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        int xx = (1<<30)-1;
        xx = xx^x;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(auto &it:a) cin>>it;
        for(auto &it:b) cin>>it;
        for(auto &it:c) cin>>it;

        int res=0;
        for(int i=0;i<n;i++){
            if((xx&a[i])==0){
                res = res|a[i];
            }
            else break;
        }
        
        for(int i=0;i<n;i++){
            if((xx&b[i])==0){
                res = res|b[i];
            }
            else break;
        }
        
        for(int i=0;i<n;i++){
            if((xx&c[i])==0){
                res = res|c[i];
            }
            else break;
        }

        if(res==x) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}