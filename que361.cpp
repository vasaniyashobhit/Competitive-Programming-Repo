#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        int ans=0;
        if(s[0]=='u'){
            s[0]='s';
            ans++;
        }
        if(s[n-1]=='u'){
            s[n-1]='s';
            ans++;
        }

        for(int i=1;i<n-1;i++){
            if(s[i]=='u'){
                if(s[i+1]=='u'){
                    s[i+1]='s';
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}