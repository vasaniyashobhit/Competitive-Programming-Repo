#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> h(n); 
        for(long long &it:h) cin>>it;
        
        for(int i=0;i<n;i++){
            vector<long long> maxright(n);
            vector<long long> maxleft(n);

            maxright[i] = 0;
            maxleft[i] = 0;
            for(int j=(i+1)%n;j!=i;){
                int prevj = j-1;
                if(prevj==-1) prevj = n-1;
                maxright[j] = max(maxright[prevj],h[prevj]);
                j++;
                j = j%n;
            }

            for(int j=i-1;j!=i;){
                if(j==-1) j = n-1;
                maxleft[j] = max(maxleft[(j+1)%n],h[j]);
                j--;
                if(j==-1) j = n-1;
                
            }

            long long sum = 0;
            for(int j=0;j<n;j++){
                sum += min(maxright[j],maxleft[j]);
            }
            cout<<sum<<" ";
        }
        cout<<endl;
    }

    return 0;
}