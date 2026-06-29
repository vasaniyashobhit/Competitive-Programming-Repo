#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        vector<vector<int>> seg (n+1,vector<int>(2*(n+1),0));
        int maxlen = 0;
        vector<int> hash(n+1,0);
        for(int i=0;i<n;i++){
            int lr = a[i];
            int sm = a[i];
            for(int j=i;j<n;j++){
                if(hash[a[j]]==1) break;
                hash[a[j]] = 1;
                lr = max(lr,a[j]);
                sm = min(sm,a[j]);
                int len = j-i+1;
                if(len==lr-sm+1){
                    if(lr-len>=0 && seg[len][lr-len]==1) maxlen = max(len,maxlen);
                    if(seg[len][lr+len]==1) maxlen = max(len,maxlen);
                    seg[len][lr] = 1;
                }
            }
            for(int i=0;i<hash.size();i++) hash[i] = 0;

        }
        cout<<maxlen<<endl;
    }

    return 0;
}