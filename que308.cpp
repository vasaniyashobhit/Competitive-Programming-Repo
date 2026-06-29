#include<bits/stdc++.h>
using namespace std;

void primefact(int n,vector<int> &hash, vector<int> &primes) {
    vector<int> factors;
    primes.push_back(2);

    while (n % 2 == 0) {
        hash[2]++;
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        if(n%i==0) primes.push_back(i);
        while (n % i == 0) {
            hash[i]++;
            n = n / i;
        }
    }

    if (n > 2) hash[n]++;
    if(n>2) primes.push_back(n);

    return;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        vector<int> hash(1e6+1,0);
        vector<int> primes;
        for(int i=0;i<n;i++) primefact(a[i],hash,primes);
        
        bool k = true;
        for(auto it:primes){
            if(hash[it]%n!=0){
                k=false;
                break;
            }
        }

        if(k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}