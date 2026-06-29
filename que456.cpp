#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        long long ans=0;
        for(int k=1;k<=n;k++){
            for(int i=0;i<n-k+1;i++){
                string a = s.substr(i,k);
                for(int j=i+1;j<n-k+1;j++){
                    string b = s.substr(j,k);
                    sort(a.begin(),a.end());
                    sort(b.begin(),b.end());

                    if(a==b){
                        ans++;
                        //cout<<a<<" "<<b<<endl;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}