#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;

    int num=-1;
    for(int i=1;i<n;i*=2){
        num=i;
    }

    vector<int> ans(n);
    for(int i=num;i<n;i++) ans[i] = i;
    int it = 0;
    for(int i=num-1;i>=0;i--){
        ans[i] = it;
        it++;
    }

    for(auto it:ans) cout<<it<<" ";
    cout<<endl;

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