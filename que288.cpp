#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        int cnt0 = 0;
        for(int i=0;i<n;i++) if(s[i]=='0') cnt0++;

        if(n%2==0){
            cout<<"BOB"<<endl;
        }
        else{
            if(s[n/2]=='0'){
                if(cnt0==1) cout<<"BOB"<<endl;
                else cout<<"ALICE"<<endl;
            }
            else{
                cout<<"BOB"<<endl;
            }
        }
    }

    return 0;
}