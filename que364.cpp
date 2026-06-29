#include<bits/stdc++.h>
using namespace std;

long long calculate(vector<long long> &axis){
    sort(axis.begin(),axis.end());
    long long n = axis.size();
    long long sum=0;
    for(long long i=0;i<n;i++){
        sum += (1ll*axis[i]*(i-(n-i-1)));
    }

    return sum;
}

int main(){
    long long n,m; cin>>n>>m;
    vector<vector<long long>> a(n,vector<long long> (m));
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            cin>>a[i][j];
            a[i][j]--;
        }
    }

    long long maxcolor = 100000;
    vector<vector<long long>> x(maxcolor);
    vector<vector<long long>> y(maxcolor);
    
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            x[a[i][j]].push_back(i);
            y[a[i][j]].push_back(j);
        }
    }

    long long ans=0;
    for(long long i=0;i<maxcolor;i++){
        ans += calculate(x[i]);
        ans += calculate(y[i]);
    }
    cout<<ans<<endl;

    return 0;
}