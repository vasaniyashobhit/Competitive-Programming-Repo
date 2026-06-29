#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long a,b,x; cin>>a>>b>>x;
        long long minans=1e9;
        long long op = 0;
        while(true){
            if(a==0 && b==0){
                long long ans = abs(a-b) + op;
                minans = min(ans,minans);
                break;
            }
            if(a>b) swap(a,b);
            long long ans = b-a + op;
            minans = min(ans,minans);
            b/=x;
            op++;
        }

        cout<<minans<<endl;
    }
}