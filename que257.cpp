#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void sieve(vector<long long> &primes) {
    long long n = 1e6 + 1;
    // creation of boolean array
    vector<bool> prime(n + 1, true);
    for (long long p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            
            // marking as false
            for (long long i = p * p; i <= n; i += p){
                prime[i] = false;
            }
                
        }
          
    }
    
    for (long long p = 2; p <= n; p++){
        if (prime[p]){ 
            primes.push_back(p);
        }
    }
    return;
}

void primefactorisation(long long k, set<long long> &st, vector<long long> &primes){
    long long nn = primes.size();
    
    for(long long i=0;i<=nn;i++){
        int b = primes[i];
        //cout<<b<<" ";
        if(k%b==0){
            st.insert(b);
        }
        if(b>k) break; 
    }

    return;
}


int main(){
    int t; cin>>t;
    vector<long long> primes;
    sieve(primes);

    while(t--){
        long long n; cin>>n;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        long long x = a[0];
        for(int i=0;i<n;i++){
            x = __gcd(x,a[i]);
        }
        for(int i=0;i<primes.size();i++){
            if(x%primes[i]!=0){
                cout<<primes[i]<<endl;
                break;
            }
        }
        
    }


    return 0;
}