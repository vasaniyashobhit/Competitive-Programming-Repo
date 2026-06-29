#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;
    long long ans;
    if(n%2==0){
        ans = ((n/2) + 1)*((n/2)+1);
    }
    else{
        ans = 2*(((n+1)/2)+1)*((n/2)+1);
    }
    cout<<ans<<endl;

    return 0;
}