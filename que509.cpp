#include<bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long mod) {
    long long res = 1;      // Initialize result
    a = a % mod;            // Update 'a' if it is >= mod

    if (a == 0) return 0;   // In case 'a' is divisible by mod

    while (b > 0) {
        // If b is odd, multiply a with the result
        if (b & 1) {
            res = (res * a) % mod;
        }
        
        // b must be even now, we shift right (divide by 2)
        b = b >> 1; 
        
        // Change a to a^2
        a = (a * a) % mod;
    }
    return res;
}

class UnionFind{
    public: vector<int> p,rank;
    public:
        UnionFind(int n){
            rank.assign(n,0);
            p.assign(n,0);
            iota(p.begin(),p.end(),0);
        }

        int findset(int i){
            return (p[i]==i) ? i : p[i] = findset(p[i]); 
        }
        bool issameset(int i,int j){
            return findset(i) == findset(j);
        }

        void unionset(int i,int j){
            if(!issameset(i,j)){
                int x = findset(i);
                int y = findset(j);
                if(rank[x]>rank[y]) p[y] = x;
                else{
                    p[x] = y;
                    if(rank[x]==rank[y]) rank[y]++;
                }
            }
        }
};


void solve(){
    int n,m,k; cin>>n>>m>>k;
    int mod = 1e9+7;
    
    UnionFind dsu(n);
    
    for(int i=0;i<=n-k;i++){
        int left = i; 
        int right = i+k-1;
        while(left<right){
            dsu.unionset(left,right);
            left++;
            right--;
        }
    }

    int leaders = 0;

    for(int i=0;i<n;i++){
        if(dsu.findset(i)==i) leaders++;
    }
    
    cout<<power(m,leaders,mod)<<endl;
    return;
}

int main(){
    
    solve();
    return 0;
}