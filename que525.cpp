#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;

    if(n<=3){
       if(n==1) cout<<1<<endl;  
       else{
        cout<<"NO SOLUTION"<<endl;
       }
       return 0;
    }
    if(n==4){
        cout<<2<<" "<<4<<" "<<1<<" "<< 3<<endl;
        return 0; 
    }

    vector<int> a(n+1);
    int lst;
    if(n%2==0) lst = n/2;
    else lst = (n/2)+1;
    int ind = 1;
    for(int i=1;i<=lst;i++){
        a[ind] = i;
        ind += 2;
    }

    ind = 2;
    
    for(int i=lst+1;i<=n;i++){
        a[ind] = i;
        ind += 2;
    }

    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}