#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int getFirstInd(int l, int r, int num, int atind, vector<vector<int>> &b){
    int s = l,e=r;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(b[mid][atind]==num){
            ans = mid;
            e = mid-1;
        }
        else if(b[mid][atind]>num) e = mid-1;
        else s = mid+1;
    }
    return ans;
}

int getLastInd(int l, int r, int num, int atind, vector<vector<int>> &b){
    int s = l,e=r;
    int ans = -1;
    while(s<=e){
        int mid = s + (e-s)/2;
        if(b[mid][atind]==num){
            ans = mid;
            s = mid+1;
        }
        else if(b[mid][atind]>num) e = mid-1;
        else s = mid+1;
    }
    return ans;
}

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    vector<vector<int>> b(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            b[i][a[i][j]-1] = j+1;
        }
    }

    sort(b.begin(),b.end());

    vector<int> ans;
    for(int i=0;i<n;i++){
        int l=0,r=n-1;
        for(int j=0;j<m;j++){
            int ind1 = getFirstInd(l,r,a[i][j],j,b);
            int ind2 = getLastInd(l,r,a[i][j],j,b);
            l = ind1;
            r = ind2;
            if(ind1==-1 || ind2==-1){
                ans.push_back(j);
                break;
            }
        }
        if(l!=-1 && r!=-1) ans.push_back(m);
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