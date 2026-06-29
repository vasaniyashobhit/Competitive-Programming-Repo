#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    string a,b,c; cin>>a>>b>>c;
	    int y0=0,y1=0,x0=0,x1=0;
	    
	    for(int i=0;i<n;i++){
	        if(b[i]=='0' && c[i]=='1'){
	            if(a[i]=='1') y1++;
	            else y0++;
	        }
	        
	        if(b[i]=='1' && c[i]=='0'){
	            if(a[i]=='1') x1++;
	            else x0++;
	        }
	    }
	    
	    if(x1>y1){
	        x1 -= y1;
	        y1 = 0;
	    }
	    else if(x1==y1){
	        x1 = 0;
	        y1 = 0;
	    }
	    else{
	        y1 -= x1;
	        x1 = 0;
	    }
	    cout<<x0<<" "<<x1<<" "<<y0<<" "<<y1<<endl;
	    int ans = 0;
	    if(x1>0 && y0>0){
	        ans += min(x1,y0);
	        int mini = min(x1,y0);
	        x1 -= mini;
	        y0 -= mini;
	    }
	    if(x0>0 && y1>0){
	        int mini = min(x0,y1);
	        ans += mini;
	        x0 -= mini;
	        y1 -= mini;
	    }
        cout<<ans<<endl;
	    ans += x0 + x1 + y0 + y1;
	    cout<<ans<<endl;
	}
	
	return 0;
}
