#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int &it:a) cin>>it;

        int count=0;
        int x=__INT_MAX__,y=__INT_MAX__;
        for(int i=0;i<n;i++){
            if(a[i]<=x){
                x = a[i];
            }
            else if(x<a[i] && a[i]<=y){
                y = a[i];
            }
            else{
                x = a[i];
                count++;
                swap(x,y);
            }
        }
        cout<<count<<endl;
    }

    return 0;
}