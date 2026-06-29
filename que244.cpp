#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long n,p; cin>>n>>p;
    vector<long long> a(n);
    for(long long &it:a) cin>>it;

    long long sum=0,ans=0;
    for(long long i=0;i<n;i++) sum+=a[i];
    ans += n*(p/sum);
    p %= sum;
    for(int i=0;i<n;i++){
        a.push_back(a[i]);
    }
    int n2 = 2*n;

    // // leaving some part
    // long long l=0,r=0,req=sum-p;
    // long long s=0,maxlen=0,ind1;
    // while(r<n){
    //     s += a[r];
    //     while(l<=r && s>req){
    //         s -= a[l];
    //         l++;
    //     }
    //     if(s<=req){
    //         if(r-l+1>=maxlen){
    //             maxlen = r-l+1;
    //             ind1 = l; 
    //         }
    //         maxlen = max(maxlen,r-l+1);
    //     }
    //     r++;
    // }
    // long long ans1 = n-maxlen;

    // listning to some part
    long long l=0,r=0,s=a[0];
    long long minlen=n+1,ind2;
    while(r<n2 && l<n2){
        while(r<n2 && s<p){
            r++;
            s += a[r];
        }
        if(s>=p){
            if(r-l+1<=minlen){
                minlen = r-l+1;
                ind2 = l;
            }
        }
        //cout<<l<<"-"<<r<<" ";

        s -= a[l];
        l++;
    }
    long long ans2 = minlen;
    cout<<(ind2%n)+1<<" ";
    
    cout<<(ans+ans2)<<endl;
    
    return 0;
}