#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<long long> a(n);
    for(long long &it:a) cin>>it;

    vector<long long>pref(n,0);
    if(a[0]<0) pref[0]=1;
    for(int i=1;i<n;i++){
        pref[i]= pref[i-1];
        if(a[i]<0) pref[i]++;
    }

    // negative
    long long even = 1,odd=0,ansneg=0,anspos=0;
    
    for(int i=0;i<n;i++){
        if(pref[i]%2==0){
            ansneg += odd;
            anspos += even;
            even++;
        }
        else{
            ansneg += even;
            anspos += odd;
            odd++;
        }
    }

    cout<<ansneg<<" "<<anspos<<endl;

    return 0;
}