#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n; cin>>n;
    n*=2;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    int ind1=-1,ind2=-1;
    for(int i=0;i<n;i++){
        if(a[i]==0 && ind1==-1) ind1 = i;
        else if(a[i]==0) ind2 = i;
    }

    vector<int> v1,v2,v3;
    v1.push_back(0);
    v2.push_back(0);

    

    for(int i=ind1+1;i<n && 2*ind1-i>=0;i++){
        if(a[i]==a[2*ind1-i]) v1.push_back(a[i]);
        else break;
    }

    for(int i=ind2+1;i<n && 2*ind2-i>=0;i++){
        if(a[i]==a[2*ind2-i]) v2.push_back(a[i]);
        else break;
    }

    int l = (ind1+ind2)/2, r = ((ind2-ind1+1)%2!=0) ? l : (ind1+ind2)/2 + 1;
    while(l>=0 && r<n){
        if(a[l]==a[r]) v3.push_back(a[l]);
        else break;
        l--;r++;
    }
    

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    sort(v3.begin(),v3.end());


    int maxans = 1;
    for(int i=0;i<v1.size();i++){
        if(v1[i] != i){
            maxans = max(i,maxans);
            break;
        }
        if(i==v1.size()-1) maxans = max(maxans,(int)v1.size());
    }
    for(int i=0;i<v2.size();i++){
        if(v2[i] != i){
            maxans = max(i,maxans);
            break;
        }
        if(i==v2.size()-1) maxans = max(maxans,(int)v2.size());
    }
    for(int i=0;i<v3.size();i++){
        if(v3[i] != i){
            maxans = max(i,maxans);
            break;
        }
        if(i==v3.size()-1) maxans = max(maxans,(int)v3.size());
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