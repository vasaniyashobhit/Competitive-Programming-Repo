#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        string ss = s+s;
        long long n = s.size(); 
        long long cnt=0,maxcnt=0;
        for(int i=0;i<2*n;i++){
            if(ss[i]=='0'){
                cnt=0;
            }
            else{
                cnt++;
                maxcnt = max(maxcnt,cnt);
            }
        }
        //cout<<maxcnt<<endl;

        if(n==1){
            if(s[0]=='1') cout<<1<<endl;
            else cout<<0<<endl;
            continue;
        }
        else if(maxcnt==2*n){
            cout<<n*n<<endl;
            continue;
        }

        long long ans=0,maxans=0;
        for(long long i=1;i<=maxcnt;i++){
            long long j = maxcnt+1-i;
            ans = i*j;
            maxans = max(ans,maxans);
        }
        cout<<maxans<<endl;
    }

    return 0;
}