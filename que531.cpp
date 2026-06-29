#include<bits/stdc++.h>
using namespace std;

long long calculateNCR(int n, int r) {
    // Base cases
    if (r > n || n < 0 || r < 0) return 0;
    if (r == 0 || r == n) return 1;

    // Since nCr is symmetrical: nCr = nC(n-r)
    // Choosing the smaller r reduces the number of iterations
    if (r > n - r) {
        r = n - r;
    }

    long long result = 1;

    // Calculate [n * (n-1) * ... * (n-r+1)] / [1 * 2 * ... * r]
    for (long long i = 1; i <= r; ++i) {
        result *= (n - r + i);
        result /= i; 
    }

    return result;
}


int main(){
    int n; cin>>n;
    vector<long long> a(max(5,n+1),0);
    a[1]=0;a[2]=6;a[3]=28;a[4]=96; 
    
    for(long long i=5;i<=n;i++){
        long long sum1 = 10;
        sum1 += 4*(i-4);
        sum1 = sum1*(i-2);

        long long sum2 = 4;
        sum2 += 2*(i-4);

        a[i] =  calculateNCR(i*i,2) - (sum1+sum2);
        
    }

    for(long long i=1;i<=n;i++) cout<<a[i]<<endl;

    return 0;
}