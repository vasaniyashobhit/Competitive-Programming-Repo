#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);

        int k = 1;
        for(int i=n-1;i>=0;i-=2){
            a[i] = k;
            k++;
        }

        int i = (n%2==0) ? 0 : 1;
        for(;i<n;i+=2){
            a[i] = k;
            k++;
        }

        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}