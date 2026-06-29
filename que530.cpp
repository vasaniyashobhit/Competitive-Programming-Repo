#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long i,j; cin>>i>>j;

        long long cycle = max(i,j);
        long long completed = (cycle-1)*(cycle-1);
        if(i>j){
            if(cycle%2==0){
                cout<<((cycle*cycle)-j+1)<<endl;
            }
            else{
                cout<<(completed+j)<<endl;
            }
        }
        else if(i<j){
            if(cycle%2==0){
                cout<<(completed+i)<<endl;
            }
            else{
                cout<<((cycle*cycle)-i+1)<<endl;
            }
        }
        else{
            cout<<(completed+cycle)<<endl;
        }
    }

    return 0;
}