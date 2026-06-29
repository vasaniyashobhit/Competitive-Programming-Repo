#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);

        for(auto &it:a) cin>>it;
        for(auto &it:b) cin>>it;

        long long sum = 0;

        for(int i=0;i<n;i++){
            if(a[i]>b[i]){
                int ind=-1;
                for(int j=i;j<n;j++){
                    if(a[j]<=b[i]){
                        ind = j;
                        break;
                    }
                }
                if(ind==-1){
                    sum = -1;
                    break;
                }
                for(int j=ind;j>i;j--){
                    swap(a[j],a[j-1]);
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}