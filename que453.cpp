#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long x; cin>>x;
        vector<int> d;
        long long x1 = x;

        if(x<10){
            cout<<0<<endl;
            continue;
        }

        long long r;
        while(x1>0){
            long long num = x1%10;
            d.push_back(num);
            x1/=10;
            if(x1<10 && x1>0){
                r = x1%10;
                break;
            }
        }
        //cout<<r<<endl;
        sort(d.begin(),d.end());
        long long sum=0,op=0;
        long long maxi=0;
        for(int i=0;i<d.size();i++){
            if(sum+d[i]>=10){
                d[i]=0;
                op++;
            }
            else{
                sum+=d[i];
                maxi = d[i];
            }
        }
        if(sum+r>=10){
            if(r>maxi){
                if(sum+1>=10){
                    op+=2;
                }
                else{
                   op++;
                }
                
            }
            else{
                op++;
            }
            cout<<op<<endl;
        }
        else cout<<op<<endl;
        
    }
}