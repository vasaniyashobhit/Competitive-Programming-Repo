#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        for(long long i=n;i<=(n+2520);i++){
            long long c = i;
            long long ans = true;
            while(c>0){
                long long k = c%10;
                //cout<<k<<" ";
                if(k!=0 && i%k!=0){
                    ans = false;
                    break;
                }
                c/=10;
            }
            if(ans==true){
                cout<<i<<endl;
                break;
            }
        }
    }

    return 0;
}