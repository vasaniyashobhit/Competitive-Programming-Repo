#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;
        int maxcount=1,count=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
                maxcount = max(maxcount,count);
            }
            else{
                count=1;
            }
            //cout<<count<<" ";
        }
        cout<<maxcount+1<<endl;
    }

    return 0;
}