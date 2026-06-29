#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    vector<long long> pow2;
    vector<long long> fact;
    fact.push_back(1);
    pow2.push_back(1);
    long long k = 2;
    while(true){
        fact.push_back(fact.back()*k);
        k++; 
        if(fact.back()>1e12) break;
    }
    k=1;
    while(true){
        if(k>1e12) break;
        k*=2;
        pow2.push_back(k);
    }
    while(t--){
        long long n; cin>>n;
        long long count = 0;
        while(n>0){
            auto it1 = lower_bound(fact.begin(),fact.end(),n);
            auto it2 = lower_bound(pow2.begin(),pow2.end(),n);
            if((*it1)>n) --it1;
            if((*it2)>n) --it2;
            if((*it1)>(*it2)){
                n -= *(it1);
            }
            else n -= *(it2);
            count++;
        }
        cout<<count<<endl;
    }

    return 0;
}