#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    } 


    vector<int> ans;
    for(int i=0;i<n;i++){
        
        set<int> st;
        for(int j=0;j<n;j++) st.insert(j+1);

        for(int j=0;j<m;j++){

            bool k = false;
            
            if(st.empty()){
                ans.push_back(j);
                break;
            }

            for (auto itr = st.begin(); itr != st.end(); ) {
                if (a[*itr-1][a[i][j]-1] != j+1) itr = st.erase(itr);
                else { k = true; ++itr; }
            }

            if(k==false){
                ans.push_back(j);
                break;
            }
        }

        if(!st.empty()) ans.push_back(m);

    }

    for(auto it:ans) cout<<it<<" ";
    cout<<endl;

    return;
}

int main() {
    // Fast I/O
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}