#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long n,m,k; cin>>n>>m>>k;
        long long ans = 1;
        long long mx=m;
        long long mr=m;
        long long ansleft;
        long long ansright;
        
        // left first;
        if(k>=2){
            long long places = k-1;
            long long daysreq = (2*places)-1;
            if(m==daysreq){
                ans+=places;
                //cout<<ans<<endl;
                ansleft = ans;
                m=0;
                //continue;
            }
            else if(m>daysreq){
                m -= daysreq;
                ans += places;
            }
            else{
                if(m%2==0){
                    ans += m/2;
                    if(k<n) ans++;
                    //cout<<ans<<endl;
                    ansleft = ans;
                    m=0;
                    //continue;
                }
                else{
                    ans += (m+1)/2;
                    //cout<<ans<<endl;
                    ansleft = ans;
                    m=0;
                    //continue;
                }
            }
        }
        //cout<<ans<<" "<<m<<endl;
        long long daysl = m;
        if(m>0){
            long long m1 = m;
            long long ans1=0;
            long long centno = mx+1-(ans);
            if(m1%2==0){
                ans1 += m1/2;
                centno++;
            }
            else ans1 += (m1+1)/2;
            //cout<<ans1<<" ";
            ans1 += ((centno-1)/2);
            //cout<<ans1<<" "<<centno<<endl;

            ans1 = min(n-k,ans1);
            ans1 = min(ans1,daysl);
            ans += ans1;
            //cout<<ans<<endl;
            ansleft = ans;
        }

        // rightfirst
        ans=1;
        m = mr;
        if(k!=n){
            long long places = n-k;
            long long daysreq = (2*places)-1;
            
            if(m==daysreq){
                ans+=places;
                //cout<<ans<<endl;
                ansright = ans;
                m=0;
                //continue;
            }
            else if(m>daysreq){
                m -= daysreq;
                ans += places;
            }
            else{
                if(m%2==0){
                    ans += m/2;
                    if(k>1) ans++;
                    //cout<<ans<<endl;
                    ansright = ans;
                    m=0;
                    //continue;
                }
                else{
                    ans += (m+1)/2;
                    //cout<<ans<<endl;
                    ansright = ans;
                    m=0;
                    //continue;
                }
            }
        }
        //cout<<ansright<<endl;
        long long daysr = m;
        if(m>0){
            long long m1 = m;
            long long ans1=0;
            long long centno = mx+1-(ans);
            if(m1%2==0){
                ans1+= m1/2;
                centno++;
            }
            else ans1 += (m1+1)/2;
            //cout<<ans1<<" ";
            ans1 += ((centno-1)/2);
            //cout<<ans1<<" "<<centno<<endl;

            ans1 = min(k-1,ans1);
            ans1 = min(ans1,daysr);
            ans += ans1;
            //cout<<ans<<endl;
            ansright = ans;
        }

        cout<<ansleft<<" "<<ansright<<endl;
        cout<<max(ansright,ansleft)<<endl;
    }

    return 0;
}