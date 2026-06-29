#include<bits/stdc++.h>
using namespace std;

void helper(int l,int r,int ind,int k,int &ans,vector<int> &pref, vector<int> &suff,vector<int> &a){
    if(l>=r) return;
    int mid = l + (r-l)/2;
    int siz = (r-l+1)/2;
    
    int prefl = (l>0) ? pref[l-1] : 0;
    int suff1 = (r<a.size()-1) ? suff[r+1] : 0;
    if(ind<=mid){
        if((pref[mid]^prefl^a[ind]^k)<(suff[mid+1]^suff1)){
            ans += siz;
        }
        helper(l,mid,ind,k,ans,pref,suff,a);
    }
    else{
        if((pref[mid]^prefl)>=(suff[mid+1]^a[ind]^k^suff1)){
            ans += siz;
        }
        helper(mid+1,r,ind,k,ans,pref,suff,a);
    }
    return;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n2,q; cin>>n2>>q;
        int n = 1<<n2;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        vector<int> pref(n);
        vector<int> suff(n);
        suff[n-1] = a[n-1];
        pref[0] = a[0];
        for(int i=1;i<n;i++) pref[i] = pref[i-1]^a[i];
        for(int i=n-2;i>=0;i--) suff[i] = suff[i+1]^a[i];

        while(q--){
            int ind,k; cin>>ind>>k;
            ind--;
            int ans=0;
            helper(0,n-1,ind,k,ans,pref,suff,a);
            cout<<ans<<endl;
        }
    }

    return 0;
}