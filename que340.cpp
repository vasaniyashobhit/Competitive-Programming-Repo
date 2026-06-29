#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin>>n;
    vector<long long> a(n);
    for(long long &it:a) cin>>it;

    long long sum=0;
    long long lar=-1,sec=-1,larind=-1,secind=-1;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(a[i]>=lar){
            sec = lar;
            secind = larind;
            lar = a[i];
            larind = i;
        }
        else if(a[i]>=sec){
            sec = a[i];
            secind = i;
        }
    }
    
    long long ans=0;
    vector<int> b;
    for(int i=0;i<n;i++){
        if(a[i]==lar){
            if(2*(sec)==sum-a[i]){
                ans++;
                b.push_back(i);
            }
        }
        else{
            if(2*lar==sum-a[i]){
                ans++;
                b.push_back(i);
            }
        }
    }
    cout<<ans<<endl;
    for(auto it:b) cout<<it+1<<" ";
    cout<<endl;
    
    
    return 0;
}