#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n,m,k; cin>>n>>m>>k;
        vector<int> a(n);
        vector<int> b(m);
        for(int &it:a) cin>>it;
        for(int &it:b) cin>>it;
        string s; cin>>s;
        sort(b.begin(),b.end());

        vector<int> curr(k);
        int c = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L') c-=1;
            else c+=1;

            curr[i] = c;
        }

        vector<int> left(k,0);
        vector<int> right(k,0);
        left[0] = curr[0];
        right[0] = curr[0];
        for(int i=1;i<k;i++){
            left[i] = min(curr[i],left[i-1]);
            right[i] = max(curr[i],right[i-1]);
            if(right[i]<0) right[i] = 0;
        }
        for(int i=0;i<k;i++) left[i] = abs(left[i]);

        vector<long long> diffans(k,0);

        for(int i=0;i<n;i++){
            int pos = a[i];
            auto xx = lower_bound(b.begin(),b.end(),pos);
            auto yy = --lower_bound(b.begin(),b.end(),pos);
            int leftmost = k;  // just left
            int rightmost = k; // just right distance
            if(pos>b[m-1]){
                rightmost = k;
                leftmost = pos-b[m-1];
            }
            else if(pos<b[0]){
                leftmost = k;
                rightmost = b[0] - pos;
            }
            else{
                rightmost = (*xx)-pos;
                leftmost = pos-(*yy);
            }
            if(rightmost>right[k-1]) rightmost = k;
            if(leftmost>left[k-1]) leftmost = k;
            cout<<leftmost<<" "<<rightmost<<endl;
            int ind1 = lower_bound(right.begin(),right.end(),rightmost) - right.begin();
            int ind2; lower_bound(left.begin(),left.end(),leftmost) - left.begin();
            //cout<<min(ind1,ind2)<<endl;
            
            if(min(ind1,ind2)<k) diffans[min(ind1,ind1)]--;

        }
        for(auto it:diffans) cout<<it<<" ";
        cout<<endl;
        diffans[0] = n-diffans[0];
        for(int i=1;i<k;i++){
            diffans[i] += diffans[i-1];
        }

        // for(auto it:diffans) cout<<it<<" ";
        // cout<<endl;
       
        
        
    }

    return 0;
}