#include<bits/stdc++.h>
using namespace std;

int check(vector<int> &a, vector<int> &b, int j){
    int n = a.size();

    int k=-1; // 0 for a. 1 for b   -1 for noresult
    for(int i=n-1;i>=0;i--){
        if(   (   ((a[i]>>j)&1)==0 && ((b[i]>>j)&1)==1   )   || (  ((a[i]>>j)&1)==1 && ((b[i]>>j)&1)==0  )   ){
            if((i+1)%2==0){
                k=1;
            }
            else k = 0;
            break;
        }
    }
        

    //cout<<k<<" ";
    int cnta=0,cntb=0;
    for(int i=0;i<n;i++){
        if(((a[i]>>j)&1)==1) cnta++;
        if(((b[i]>>j)&1)==1) cntb++;
    }

    if(k==-1){
        return -1;
    }
    else if(k==0){
        if(cnta%2==0){
            if(cntb%2==0) return -1;
            else return 0;
        }
        else{
            if(cntb%2==0) return 0;
            else return -1;
        }
    }
    else{
        if(cntb%2==0){
            if(cnta%2==0) return -1;
            else return 1;
        }
        else{
            if(cnta%2==0) return 1;
            else return -1;
        }
    }

    return -1;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int &it:a) cin>>it;
        for(int &it:b) cin>>it;


        bool fans = false;
        for(int i=20;i>=0;i--){
            int ans = check(a,b,i);  // 0 for ajisai.. 1 for mai  -1 for tie 
            if(ans==1){
                cout<<"Mai"<<endl;
                fans = true;
                break;
            }
            else if(ans==0){
                cout<<"Ajisai"<<endl;
                fans = true;
                break;
            }
        }
        if(fans==false) cout<<"Tie"<<endl;
    }

    return 0;
}