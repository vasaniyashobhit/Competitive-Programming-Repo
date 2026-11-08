#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(int x, int y, vector<int> a){
    bool ans = true;
    if(a[0]<x || a[1]<y) ans = false;
    a[0] -= x;
    a[1] -= y;

    int sum = a[0]+a[1];
    if(sum<y) ans = false;
    sum -= y;

    for(int i=2;i<=5;i++) sum += a[i];
    if(sum<x+y) ans = false;
    sum -= (x+y);

    for(int i=6;i<=9;i++) sum += a[i];
    if(sum<2*x+y) ans = false;
    sum -= (2*x+y);

    return ans;
}

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vector<int> a(10,0);

    for(int i=0;i<n;i++){
        a[s[i]-'0']++;
    }

    int maxans = -1;
    for(int x=0;x<=n;x++){
        int l=0,r=n;
        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(x,mid,a)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        if(ans!=-1) maxans = max(x+ans,maxans);
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