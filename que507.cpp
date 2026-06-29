#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        sort(a.begin(),a.end());

        map<int,int> mp;
        
        for(int i=0;i<n;i++){
            if(mp.find(a[i])==mp.end()){
                mp[a[i]] = 1;
            }
            else mp[a[i]] ++;
        }

        vector<int> b;
        b.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]) b.push_back(a[i]);
        }

        bool ans = false;
        // A and E are different
        int bn = b.size();
        for(int i=0;i<bn;i++){

            if((i==bn-1) || (b[i+1]-b[i]>k)){
                // a and e are same
                int count = mp[b[i]];
                if(count%2==0) ans = true;

                if(i>0 && b[i]-b[i-1]<=k){
                    if(count%2!=0) ans = true;
                }
            }
        }

        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


        // A and E are same
    }
}