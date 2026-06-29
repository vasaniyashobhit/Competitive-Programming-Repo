#include<bits/stdc++.h>
using namespace std;

long long counter(string &a, string &b, string &s,long long j){
    long long n = a.size();
    set<char> selected;
    for(int i=0;i<s.size();i++){
        if((j>>i)&1==1){
            selected.insert(s[i]);
        }
    }

    long long ans=0;
    long long l=0,r=0,len=0;
    while(l<n && r<n){
        if(a[r]==b[r] || selected.find(a[r])!=selected.end()){
            len++;
            r++;
        }
        else{
            ans+=(len)*(len+1)/2;
            len = 0;
            r++;
            l=r;
        }
    }
    ans += (len)*(len+1)/2;
    return ans;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n,k; cin>>n>>k;
        string a; cin>>a;
        string b; cin>>b;

        set<char> st;
        for(int i=0;i<n;i++) st.insert(a[i]);
        string s = "";
        for(auto it:st) s+=it;
        long long m = st.size();

        long long maxans = 0;
        k = min(m,k);

        for(int j=0;j<(1<<m);j++){
            int setbits = __builtin_popcountll(j);
            if(setbits==k){
                long long ans = counter(a,b,s,j);
                maxans = max(ans,maxans);
            }
        }
        cout<<maxans<<endl;
    }

    return 0;
}