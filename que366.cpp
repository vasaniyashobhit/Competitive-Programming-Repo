#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,x,y; cin>>n>>x>>y;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long cnt1=0;
        for(int i=0;i<n;i++){
            if(a[i]%2!=0) cnt1++;
        }

        if(cnt1%2==0){
            if((y%2) == (x%2)){
                cout<<"Alice"<<endl;
            }
            else{
                cout<<"Bob"<<endl;
            }
        }
        else{
            if((y%2)==(x%2)){
                cout<<"Bob"<<endl;
            }
            else cout<<"Alice"<<endl;
        }
    }

    return 0;
}