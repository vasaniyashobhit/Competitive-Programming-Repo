#include<iostream>
using namespace std;
 
int main(){
    int t; cin>>t;
    while(t--){
        long long a,b; cin>>a>>b;
        long long cnt=0;
        if(a<=b){
            while(a<b){
                cnt++;
                a = a<<1ll;
            }
        }
        else{
            while(a>b && a%2==0){
                a = a>>1ll;
                cnt++;
            }
        }

        if(a==b){
            cnt = (cnt%3==0) ? cnt/3 : cnt/3 + 1;
            cout<<cnt<<endl;
        }
        else cout<<-1<<endl;
    }

    return 0;
}