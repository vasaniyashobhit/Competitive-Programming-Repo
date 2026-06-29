#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,x,y; cin>>n>>x>>y;
        string s; cin>>s;
        vector<long long> p(n);
        for(long long &it:p) cin>>it;

        if(n==1){
            if(s[0]=='0'){
                if(x>y && x+y>=p[0]) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else{
                if(y>x && x+y>=p[0]) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            continue;
        }

        bool ka=false,kb=false;

        long long asum=0,bsum=0,reqtotal=0,aspace=0,bspace=0,sump=0;
        for(long long i=0;i<n;i++){
            sump += p[i];
            if(s[i]=='0'){
                ka=true;
                long long d = (p[i]/2)+1;
                asum += d;
                reqtotal += p[i]-d;
                if(d-(p[i]-d)-1>0)  bspace += d-(p[i]-d)-1;
            }
            else{
                kb=true;
                long long d = (p[i]/2)+1;
                bsum += d;
                reqtotal = p[i]-d;
                if(d-(p[i]-d)-1>0)  aspace += d-(p[i]-d)-1;
            }
        }


        if(asum>x || bsum>y || (x+y<sump)){
            cout<<"NO"<<endl;
            continue;
        }

        if(ka==false && y<x+n){
            cout<<"NO"<<endl;
            continue;
        } 
        if(kb==false && x<y+n){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }

    return 0;
}