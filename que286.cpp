#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int &it:a) cin>>it;
        for(int &it:b) cin>>it;

        int k=-1; // 0 for a. 1 for b   -1 for noresult
        for(int i=n-1;i>=0;i--){
            if((a[i]==0 && b[i]==1) || (a[i]==1 && b[i]==0)){
                if((i+1)%2==0){
                    k=1;
                }
                else k = 0;
                break;
            }
        }

        int cnta=0,cntb=0;
        for(int i=0;i<n;i++){
            if(a[i]==1) cnta++;
            if(b[i]==1) cntb++;
        }

        if(k==-1){
            cout<<"Tie"<<endl;
        }
        else if(k==0){
            if(cnta%2==0){
                if(cntb%2==0) cout<<"Tie"<<endl;
                else cout<<"Ajisai"<<endl;
            }
            else{
                if(cntb%2==0) cout<<"Ajisai"<<endl;
                else cout<<"Tie"<<endl;
            }
        }
        else{
            if(cntb%2==0){
                if(cnta%2==0) cout<<"Tie"<<endl;
                else cout<<"Mai"<<endl;
            }
            else{
                if(cnta%2==0) cout<<"Mai"<<endl;
                else cout<<"Tie"<<endl;
            }
        }
    }

    return 0;
}