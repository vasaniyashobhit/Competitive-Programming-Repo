#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        string s; cin>>s;

        int zr=0,on=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') on = on^a[i];
            else zr = zr^a[i];
        }

        vector<int> pref(n,0);
        pref[0] = a[0];
        for(int i=1;i<n;i++) pref[i] = pref[i-1]^a[i];

        int q; cin>>q;
        while(q--){
            int type; cin>>type;
            if(type==1){
                int l,r; cin>>l>>r;
                on = on^(pref[r-1]);
                zr = zr^(pref[r-1]);
                if(l>1){
                    on = on^(pref[l-2]);
                    zr = zr^(pref[l-2]);
                }
            }
            else{
                int g; cin>>g;
                if(g==0) cout<<zr<<" ";
                else cout<<on<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}