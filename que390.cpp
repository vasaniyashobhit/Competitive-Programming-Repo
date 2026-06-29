#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        int ext=0,cnt=0;
        bool ans = false;
        while(n>0){
            if((n==k) || (n+1==k && ext==1)){
                ans = true;
                break;
            }
            if(n%2!=0) ext=1;
            n/=2;
            cnt++;
        }

        if(ans==true) cout<<cnt<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}