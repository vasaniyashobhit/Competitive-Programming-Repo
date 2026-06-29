#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t; 
    while(t--){
        int l,r; cin>>l>>r;
        int x,y,z;
        int ind=-1;
        for(int i=30;i>=0;i--){
            if(((l>>i)&1)^((r>>i)&1)){
                ind = i;
                //cout<<ind<<endl;
                break;
            }
        }
        int num = (1<<ind);
        x = l+num - ((l+num)%num);
        //cout<<x<<endl;
        y = x-1;

        for(int i=l;i<=r;i++){
            if(i!=x && i!=y){
                z = i;
                break;
            }
        }
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
}