#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,q; cin>>n>>q;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    vector<int> queries(q);
    for(int &it:queries) cin>>it;

    vector<int> hash(51,0);
    vector<pair<int,int>> b;
    for(int i=0;i<n;i++){
        if(hash[a[i]]==0){
            b.push_back({a[i],i});
            hash[a[i]] = 1;
        }
    }

    for(int i=0;i<q;i++){
        int color = queries[i];
        int ind;
        for(int j=0;j<b.size();j++){
            if(b[j].first==color){
                ind = b[j].second;
            }
        }
        cout<<ind+1<<" ";
        for(int j=0;j<b.size();j++){
            if(b[j].first==color) b[j].second = 0;
            else if(b[j].second < ind) b[j].second++;
        }

    }
    cout<<endl;
    return;

}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    while (t--) solve();

    return 0;
}