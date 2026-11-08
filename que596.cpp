#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(vector<int> &ans) {
    int n; cin>>n;
    cout<<ans[n]<<endl;
    return;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> ans(1e6+1,0);
    ans[1] = 1;
    for(int i=2;i<=1e6;i++){
        ans[i] = ans[i-1];
        int num =  i;
        int cnt = 0;
        while(num>0){
            int d = num%10;
            if(d!=0) cnt++;
            num/=10;
        }
        if(cnt==1) ans[i]++;
    }

    int t; cin >> t;
    while (t--) solve(ans);

    return 0;
}