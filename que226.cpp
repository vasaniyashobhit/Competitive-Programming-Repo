#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &pref, int l, int k, int mid){
    l--,mid--;
    int num=0;
    for(int i=0;i<=29;i++){
        int cnt = (l>0) ? pref[mid][i]-pref[l-1][i] : pref[mid][i];
        if(cnt==(mid-l+1)){
            num += (1<<i);
        }
    }
    if(num>=k) return true;
    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        int q; cin>>q;

        vector<vector<int>> pref(n,vector<int>(32,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<=29;j++){
                pref[i][j] = (i>0) ? pref[i-1][j] : 0 ;
                if((a[i]&(1<<j))!=0){
                    pref[i][j]++;
                }
            }
        }

        while(q--){
            int l,k; cin>>l>>k;
            int s=l,e=n;
            int ans = -1;
            while(s<=e){
                int mid = s + (e-s)/2;
                if(check(pref,l,k,mid)){
                    ans = mid;
                    s = mid+1;
                }
                else e = mid-1;
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }

    return 0;
}