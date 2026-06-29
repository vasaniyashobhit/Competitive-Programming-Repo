#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    long long l,w,r,g,b; cin>>l>>w>>r>>g>>b;
	    multiset<long long> walls;
	    multiset<long long> colors;
	    colors.insert(r);
	    colors.insert(g);
	    colors.insert(b);
	    walls.insert(l);
	    walls.insert(w);
	    walls.insert(l);
	    walls.insert(w);
	    
        long long ans=0;
	    while(colors.size()>0){
	        long long c = *(colors.rbegin());
            long long w = *(walls.rbegin());
            colors.erase(--(colors.end()));
            walls.erase(--(walls.end()));
            cout<<w<<" "<<c<<endl;
            if(w>c){
                walls.insert(w-c);
                ans++;
            }
            else if(w==c){
                ans++;
            }
            else{
                colors.insert(c-w);
                ans++;
            }
	    }
        cout<<ans<<endl;
	    
	}
	
	return 0;
}