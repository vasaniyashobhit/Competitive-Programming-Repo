#include <bits/stdc++.h>
using namespace std;

bool check(long long b,long long g,long long x,long long y,long long n, long long mid){
    long long bcnt = mid*x;
    long long gcnt = mid*y;
    long long remb = b-bcnt,remg=g-gcnt;
    long long ext = (mid*(n-(x+y)));
    if(remb+remg<=ext) return true;
    return false;
}

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    long long b,g,x,y,n; cin>>b>>g>>x>>y>>n;
	    
	    if(x+y>n){
	        cout<<-1<<endl;
	        continue;
	    }
	    
	    int maxbox = min(b/x,g/y);
	    long long ans = -1;
        long long l=1,r=maxbox;
        while(l<=r){
            long long mid = l + (r-l)/2;
            if(check(b,g,x,y,n,mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            } 
        }
        cout<<ans<<endl;
	}

}
