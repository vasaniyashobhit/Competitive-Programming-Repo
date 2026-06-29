#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main(){
    int t; cin>>t;
    vector<long long> v;
    for(long long a=1;a<=1e5;a+=2){
        long long b = (a*a-1)/2;
        long long c = b+1;
        if((a*a + b*b == c*c) && (c = a*a-b) && (a>0 && b>0 && c>0)){
            v.push_back(c);
        }
    }
    while(t--){
        int n; cin>>n;
        auto it = upper_bound(v.begin(),v.end(),n);
        long long ans = it-v.begin();
        cout<<ans<<endl;
    }

    return 0;
}