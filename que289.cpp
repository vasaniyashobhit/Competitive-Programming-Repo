#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string a,b; cin>>a>>b;

        vector<int> pref(n,0);
        if(a[0]=='1') pref[0]=1;
        
        for(int i=1;i<n;i++){
            if(a[i]=='1') pref[i]=1;
            pref[i] += pref[i-1];
        }

        bool ans=true;
        int inversions = 0;
        for(int i=n-1;i>=0;i--){
            if(inversions%2!=0){
                if(a[i]=='1') a[i]='0';
                else a[i] = '1';
                pref[i] = (i+1) - pref[i];
            }

            if(a[i] != b[i]){
                if(((i+1)%2==0) && (pref[i]==(i+1)/2)){
                    inversions++;
                }
                else{
                    ans = false;
                    break;
                }
            }
        }
        if(ans==true){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }

    return 0;
}