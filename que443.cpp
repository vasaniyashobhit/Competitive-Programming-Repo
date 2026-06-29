#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int &it:a) cin>>it;

    int gcd=a[0];
    bool k = false;
    for(int i=0;i<n;i++){
        gcd = __gcd(gcd,a[i]);
        if(a[i]==1) k=true;
    }
    if(gcd>1){
        cout<<-1<<endl;
        return 0;
    }
    if(k==true){
        int cnt=0;
        for(int i=0;i<n;i++) if(a[i]!=1) cnt++;
        cout<<cnt<<endl;
        return 0;
    }

    int nearest = n;
    for(int i=0;i<n;i++){
        int g = a[i];
        for(int j=i+1;j<n;j++){
            g = __gcd(g,a[j]);
            if(g==1){
                nearest = min(nearest,j-i);
                break;
            }
        }
    }
    int ans = n-1+nearest;
    cout<<ans<<endl;
}