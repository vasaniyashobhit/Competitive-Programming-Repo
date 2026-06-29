#include<bits/stdc++.h>
using namespace std;

long long func(vector<long long> &prefa, vector<long long> &prefb, int x,int y){
    long long n = prefa.size();
    long long m = prefb.size();

    // x in prefa, y in prefb

    long long cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(prefa[i]>=y) cnt2++;
    }
    for(int i=0;i<m;i++){
        if(prefb[i]>=x) cnt1++;
    }

    return (cnt1*cnt2);
}

int main(){
    long long n,m,k; cin>>n>>m>>k;
    vector<long long> a(n);
    vector<long long> b(m);

    for(long long &it:a) cin>>it;
    for(long long &it:b) cin>>it;

    vector<long long> prefa(n);
    vector<long long> prefb(m);

    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]==0) cnt = 0;
        else cnt++;
        prefa[i] = cnt;
    }

    cnt = 0;
    for(int i=0;i<m;i++){
        if(b[i]==0) cnt=0;
        else cnt++;
        prefb[i] = cnt;
    }

    long long ans = 0;

    for(int i=1;i*i<=k;i++){
        if(k%i!=0) continue;
        ans += func(prefa,prefb,i,k/i);
        if(i*i != k) ans += func(prefa,prefb,k/i,i);
    }

    cout<<ans<<endl;

    return 0;
}