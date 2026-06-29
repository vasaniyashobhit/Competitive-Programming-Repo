#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        string f,l; cin>>f>>l;
        string m(n,'0');
        for(int i=0;i<n;i++){
            if(f[i]=='1' && l[i]=='1') m[i] = '0';
            else if(f[i]=='0' && l[i]=='0') m[i] = '0';
            else m[i] = '1';
        }

        string A=f,B,C;
        int len = (1<<k)+1;
        if(len%3==0){
            C=l;
            B=m;
        }
        else{
            C=m;
            B=l;
        }
        vector<long long> x(3,0);
        vector<long long> y(3,0);
        for(int i=0;i<n;i++){
            if(A[i]=='0') x[0]++;
            else y[0]++;
            
            if(B[i]=='0') x[1]++;
            else y[1] ++;

            if(C[i]=='0') x[2]++;
            else y[2]++;
        }

        long long ans = ((x[0]*y[0]) + (x[1]*y[1]) + (x[2]*y[2]))*(len/3);
        if(len%3==1) ans += (x[0]*y[0]);
        else if(len%3==2) ans += (x[0]*y[0]) + (x[1]*y[1]);

        cout<<ans<<endl;

    }
}