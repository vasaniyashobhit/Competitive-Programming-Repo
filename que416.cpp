#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,h,l; cin>>n>>h>>l;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        sort(a.begin(),a.end());
        int m = max(h,l);
        int s = min(h,l);
        
        int left = 0, right=n-1;
        int count=0;
        while(left<right){
            if(a[left]>s) break;
            if(a[right]>m){
                right--;
                continue;
            }
            count++;
            left++;
            right--;
        }
       
        cout<<count<<endl;
    }

    return 0;
}