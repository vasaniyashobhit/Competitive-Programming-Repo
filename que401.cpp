#include<bits/stdc++.h>
using namespace std;

int main(){
    
    
        long long n; cin>>n;
        string s; cin>>s;
        long long q; cin>>q;

        long long n1=0,n2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='+') n1++;
            else n2++;
        }

        while(q--){
            long long x,y; cin>>x>>y;
            long long diff = (min(n1,n2)*(max(x,y))) - (max(n1,n2)*min(x,y));
            // if((diff>=0) && (diff%(abs(x-y))==0) &&  (diff/(abs(x-y))<=n)){
            //     cout<<"YES"<<endl;
            // }
            // else cout<<"NO"<<endl;
            if(diff==0) cout<<"YES"<<endl;
            else if(diff<0) cout<<"NO"<<endl;
            else if(abs(x-y)==0) cout<<"NO"<<endl;
            else{
                long long d = abs(x-y);
                if((diff%d==0) && ((diff/d)<=n)) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }

        }
    

    return 0;
}