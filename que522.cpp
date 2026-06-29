#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<long long> a(n-1);
    for(long long &it:a) cin>>it;

    long long total = n*(n+1)/2;
    long long sum = 0;
    for(long long i=0;i<n-1;i++) sum += a[i];
    cout<<total-sum<<endl;
}