#include<bits/stdc++.h>
using namespace std;

void primefact(int a, map<int,int> &primecount, set<int> &diffp){
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            if(primecount.find(i)==primecount.end()) primecount[i] = 0;
            diffp.insert(i);
            
            while(a%i==0){
                a/=i;
                primecount[i]++;
            }
        }
        
    }
    if(a>1){
        if(primecount.find(a)==primecount.end()){
            diffp.insert(a);
            primecount[a] = 1;
        }
        else primecount[a]++;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        vector<int> a(n);
        for(int &it:a) cin>>it;
        map<int,int> primecount; 
        set<int> diffp;

        for(int i=0;i<n;i++){
            primefact(a[i],primecount,diffp);
        }

        long long mod = 1e9+7;
        long long ans = 1;
        // for(auto it:diffp){
        //     cout<<it<<"-"<<primecount[it]<<" ";
        // }
        // cout<<endl;
        for(auto it:diffp){
            ans = ((ans%mod)*((primecount[it]+1)%mod))%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}