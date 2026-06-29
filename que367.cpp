#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        string s; cin>>s;
        vector<int> a;
        for(int i=0;i<n;i++){
            if(s[i]=='*') a.push_back(i);
        }

        if(a.size()==0 || a.size()==n || a.size()==1){
            cout<<0<<endl;
            continue;
        }

        long long nn = a.size();
        long long ans=0;
        if(nn%2==0){
            long long k = a[nn/2] - nn/2;
            for(int i=0;i<n;i++){
                if(s[i]=='*'){
                    ans += abs(k-i);
                    k++;
                }
            }
            cout<<ans<<endl;
        }
        else{
            long long k = a[nn/2] - nn/2;
            for(int i=0;i<n;i++){
                if(s[i]=='*'){
                    ans += abs(k-i);
                    k++;
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}