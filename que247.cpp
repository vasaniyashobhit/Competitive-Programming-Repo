#include<iostream>
#include<vector>
#include<map>
#include<string>
//#include <cstring>
using namespace std;

void sieve(vector<int> &primes, int n){
    int maxn = n+1;
    vector<int> isprime(maxn,1);
    isprime[0] = isprime[1] = 1;
    for(int i=2;i*i<maxn;i++){
        if(isprime[i]){
            for(int j=i*i;j<maxn;j+=i){
                isprime[j] = 0;
            }
        }
    }
    for(int i=2;i<maxn;i++){
        if(isprime[i]) primes.push_back(i);
    }
    return;
}

void pf(vector<int> &primes, vector<int> &primefactors, int num){
    for(int i=0;i<primes.size();i++){
        if(num%primes[i]==0){
            primefactors.push_back(primes[i]);
            while(num%primes[i]==0){
                num /= primes[i];
            }
        }
        if(num==1) break;
    }
    return;
}

int main(){
    int n,m; cin>>n>>m;
    vector<int> primes;
    sieve(primes,n);
    map<int,int> mp;
    for(int i=0;i<=primes.size();i++){
        mp[primes[i]] = 0;
    }
    
    vector<int> hash(n+1,0);
    while(m--){
        string s; cin>>s;
        string s1 = s.substr(2,s.size()-2);
        int num = stoi(s1);
        if(s[0]=='+' && hash[num]==1) cout<<"Already on"<<endl;
        else if(s[0]=='-' && hash[num]==0) cout<<"Already off"<<endl;
        vector<int> primefactors;
        pf(primes,primefactors,num);
        if(s[0]=='+'){
            if(check()){

            }
            else{
                
            }
        }
        else{

        }
    }


    return 0;
}