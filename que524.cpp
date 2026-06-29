#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;
    long long sum = 0;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            sum += a[i-1]-a[i];
            a[i] = a[i-1];
        }
    }
    cout<<sum<<endl;


    return 0;
}