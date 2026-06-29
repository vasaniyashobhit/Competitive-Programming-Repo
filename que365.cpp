#include<bits/stdc++.h>
using namespace std;

bool check(vector<long long> &a, vector<long long>&b, long long &ind){
    int n = a.size();
    int k1=0,k2=ind;
    for(int i=0;i<n;i++){
        if(a[k1+i]>=b[(k2+i)%n]) return false;
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        vector<long long> b(n);
        vector<long long> c(n);
        for(long long &it:a) cin>>it;
        for(long long &it:b) cin>>it;
        for(long long &it:c) cin>>it;
        
        long long ans1=0;
        for(long long i=0;i<n;i++){
            if(check(a,b,i)){
                ans1 += n;
            }
        }

        long long ans2=0;
        for(long long i=0;i<n;i++){
            if(check(b,c,i)){
                ans2 ++;
            }
        }
        long long ans = ans1*ans2;
        cout<<ans<<endl;
    }

    return 0;
}