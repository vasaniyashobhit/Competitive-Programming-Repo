#include<bits/stdc++.h>
using namespace std;

void primeFactors(long long n) {
    // Handle factor 2 separately to optimize the loop
    long long nn = n;
    long long cnt=0;
    vector<int> ans;
    while (n % 2 == 0) {
        ans.push_back(2);
        n /= 2;
    }

    // Check for odd factors from 3 up to the square root of n
    for (long long i = 3; i * i <= n; i += 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2 after the loop, print it
    if (n > 2) {
        ans.push_back(n);
    }

    if(ans.size()<3){
        cout<<"NO"<<endl;
        return;
    }

    long long p=1;
    for(int i=1;i<ans.size();i++) p*=ans[i];

    long long a=ans[0],b=1,c=0;
    bool k = false;
    for(int i=1;i<ans.size()-1;i++){
        b*=ans[i];
        c = p/b;
        if(a!=b && a!=c && b!=c){
            k=true;
            break;
        }
    }
    if(k){
        cout<<"YES"<<endl;
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    else cout<<"NO"<<endl;

    // if(ans.size()<3){
    //     cout<<"NO"<<endl;
    //     return;
    // }
    // long long a=ans[0],b=ans[1],c=-1,j=2;
    // while(a==b && j<ans.size()){
    //     b*=ans[j];
    //     j++;
    // }
    // if(j==ans.size()){
    //     cout<<"NO"<<endl;
    //     return;
    // }
    // c = ans[j];
    // while((a==c || b==c) && j<ans.size()){
    //     c*=ans[j];
    //     j++;
    // }
    // if(c==a || c==b){
    //     cout<<"NO"<<endl;
    // }
    // else{
    //     c *= 
    // }

    // if(cnt<3) cout<<"NO"<<endl;
    // else{
    //     cout<<"YES"<<endl;
    //     long long a = ans[0];
    //     long long b = ans[1];
    //     long long c = nn/(a*b);
    //     cout<<a<<" "<<b<<" "<<c<<endl;
    // }
    return;
}


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        primeFactors(n);
    }

    return 0;
}