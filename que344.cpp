#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;

        if(k%2!=0){
            for(int i=1;i<=k;i++) cout<<n<<" ";
            cout<<endl;
            continue;
        }

        vector<int> a(k,0);
        
        int nt=0;
        for(int i=30;i>=0;i--){
            if(((n>>i)&1)==1){
                for(int j=0;j<k;j++){
                    if(j==k-nt-1) continue;
                    if(k-nt-1<0 && j==k-1) continue;
                    a[j] = a[j]|(1<<i);
                }
                nt++;
            }
            else{
                int nn = min(nt,k);
                if(nn%2!=0) nn--;
                for(int j=k-1;j>k-1-nn;j--){
                    a[j] = a[j]|(1<<i);
                }
            }
        }
        for(int i=0;i<k;i++) cout<<a[i]<<" ";
        cout<<endl;
    }

    return 0;
}