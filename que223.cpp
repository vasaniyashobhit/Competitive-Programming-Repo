#include<iostream>
#include<vector>
using namespace std;

bool check(vector<pair<int,int>>a,int k){
    pair<int,int> curr = {0,0};
    int n = a.size();
    for(int i=0;i<n;i++){
        if(curr.second+k<a[i].first){
            return false;
        }
        else if(curr.first-k>a[i].second){
            return false;
        }
        
        if(curr.first<=a[i].first){
            curr.first = a[i].first;
            curr.second = min(curr.second+k,a[i].second);
        }
        else{
            curr.first = max(curr.first-k,a[i].first);
            if(a[i].second<=curr.first) curr.second = a[i].second;
            else curr.second = min(curr.second+k,a[i].second);
        }

    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,int>> a(n,{0,0});
        for(auto &it:a) cin>>it.first>>it.second;

        int ans = -1;
        int l = 0,r=1e9;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(a,mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}