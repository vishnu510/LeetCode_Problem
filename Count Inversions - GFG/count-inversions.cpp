// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  #define ll long long
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll int merge(ll arr[], ll l, ll mid, ll r){
        ll n1 = mid - l +1;
        ll int inv = 0;
        ll n2 = r - mid;
        vector<ll> a(n1), b(n2);
        for(ll i=0;i<n1;i++){
            a[i] = arr[l+i];
        }
        for(ll i=0;i<n2;i++){
            b[i] = arr[mid+ 1+ i];
        }
        ll i = 0, j =0, k = l;
        while(i<n1 && j < n2){
            if(a[i] <=  b[j]){
                arr[k++] = a[i++];
            }
            else{
                arr[k] = b[j];
                inv += n1 - i;
                k++;
                j++;
                
            }
        }
        while(i < n1){
            arr[k++] = a[i++];
        }
        while(j < n2){
            arr[k++] = b[j++];
        }
        return inv;
    }
    ll int mergeSort(ll arr[], ll l, ll r){
        ll int inv = 0;
        if(l < r){
            int mid = l + (r- l)/2;
            inv += mergeSort(arr,l,mid);
            inv += mergeSort(arr,mid+1,r);
            
            inv += merge(arr,l,mid,r);
        }
        return inv;

    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        ll int inv = mergeSort(arr,0,N-1);
        return inv;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends