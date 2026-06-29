#include<bits/stdc++.h>
using namespace std;

bool check(string s,char c, int n){
    for(int i=0;i<n;i++){
        if(s[i]!=c) return false;
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        char c; cin>>c;
        string s; cin>>s;

        if(check(s,c,n)){
            cout<<0<<endl;
        }
        else{
            bool k = false;
            int ans=-1;
            for(int i=1;i<=n;i++){
                bool k1 = true;
                for(int j=i;j<=n;j+=i){
                    if(s[j-1]!=c) k1 = false;
                }
                if(k1==true){
                    k=true;
                    ans=i;
                    break;
                }
            }
            if(k==true){
                cout<<1<<endl;
                cout<<ans<<endl;
            }
            else{
                cout<<2<<endl;
                cout<<n-1<<" "<<n<<endl;
            }
        }
    }

    return 0;
}