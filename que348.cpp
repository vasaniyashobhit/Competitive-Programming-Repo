#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<long long> a,int n)
{

    // If size of the arr[] is even
    if (n % 2 == 0) {

        // Applying nth_element
        // on n/2th index
        nth_element(a.begin(),
                    a.begin() + n / 2,
                    a.end());

        // Applying nth_element
        // on (n-1)/2 th index
        nth_element(a.begin(),
                    a.begin() + (n - 1) / 2,
                    a.end());

        // Find the average of value at
        // index N/2 and (N-1)/2
        return (double)(a[(n - 1) / 2]
                        + a[n / 2])
               / 2.0;
    }

    // If size of the arr[] is odd
    else {

        // Applying nth_element
        // on n/2
        nth_element(a.begin(),
                    a.begin() + n / 2,
                    a.end());

        // Value at index (N/2)th
        // is the median
        return (double)a[n / 2];
    }
}


int main(){
    int t; cin>>t;
    while(t--){
        long long n,l,r; cin>>n>>l>>r;
        vector<long long> a(n);
        for(long long &it:a) cin>>it;

        sort(a.begin(),a.end());
        double median = findMedian(a,n);
        double toselect=-1;
        if(median<=l) toselect=l;
        else if(median>=r) toselect=r;
        else toselect = median;
        long long f = (long long) toselect;

        long long ans=0;
        for(int i=0;i<n;i++){
            ans += abs(f-a[i]);
        }
        cout<<ans<<endl;

        // int mead=(int)median;
        // cout<<median<<" "<<mead<<endl;
    }

    return 0;
}