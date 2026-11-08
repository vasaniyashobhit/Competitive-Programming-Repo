#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n; 
    vector<vector<int>> a(n,vector<int>(4));
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
    } 

    int maxans = 0;
    for(int m=1;m<=n;m++){
        int cnt = 1;
        for(int i=0;i<n;i++){
            int left = cnt, right = m-cnt+1;
            if((left<a[i][0] || left>a[i][1]) && (right<a[i][2] || right>a[i][3])) cnt++;
            if(cnt==m+1) break;
        }
        if(cnt==m+1) maxans = m;
    }

    cout<<maxans<<endl;
    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}