#include<bits/stdc++.h>
using namespace std;



void merge(vector<long long>& arr, long long left, long long mid, long long right,long long &count){                     
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            count += n1-i;
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<long long>& arr, long long left, long long right, long long &count){
    
    if (left >= right)
        return;

    long long mid = left + (right - left) / 2;
    mergeSort(arr, left, mid,count);
    mergeSort(arr, mid + 1, right,count);
    merge(arr, left, mid, right,count);
}


int main(){
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        vector<pair<long long,long long>> a(n,{0,0});
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            cin>>a[i].second;
        }

        sort(a.begin(),a.end());
        vector<long long> b(n);
        for(int i=0;i<n;i++) b[i]=a[i].second;
        long long count=0;
        mergeSort(b,0,n-1,count);
        cout<<count<<endl;
    }

    return 0;
}