#include<bits/stdc++.h>
using namespace std;

bool check(int ind,vector<int> &queries,vector<pair<int,int>> &seg, int n){
    int q = queries.size();
    int m = seg.size();
    vector<int> a(n,0);

    for(int i=0;i<=ind;i++){
        a[queries[i]-1] = 1;
    }

    vector<int> pref(n);
    pref[0] = a[0];
    for(int i=1;i<n;i++){
        pref[i] = pref[i-1];
        if(a[i]==1) pref[i]++;
    }

    bool ans = false;
    for(int i=0;i<m;i++){
        pair<int,int> s = seg[i];
        s.first--; s.second--;
        int cnt1 = pref[s.second];
        if(s.first>0) cnt1 -= pref[s.first-1];
        int cnt0 = s.second-s.first+1-cnt1;
        if(cnt1>cnt0){
            ans = true;
            break;
        }
    }
    return ans;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vector<pair<int,int>> seg(m);
        for(int i=0;i<m;i++) cin>>seg[i].first>>seg[i].second;
        int q; cin>>q;
        vector<int> queries(q);
        for(int &it:queries) cin>>it;

        int l=0,r=q-1;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(mid,queries,seg,n)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        if(ans==-1) cout<<-1<<endl;
        else cout<<(ans+1)<<endl;
    }
}