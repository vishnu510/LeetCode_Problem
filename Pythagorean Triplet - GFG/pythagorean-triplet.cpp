// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    sort(arr,arr+n);
	    int left = 0,mid = left+1,right = mid+1;
	    while(left<=n-3){
	        int a = arr[left],b=arr[mid],c = arr[right];
	        if((a*a)+(b*b)==(c*c)){
	            return true;
	        }
	        if(right!=n-1){
	            right++;
	        }
	        if(right==n-1 && mid!=n-2){
	            mid++;
	            right = mid+1;
	        }
	        if(right==n-1 && mid==n-2){
	            left++;
	            mid = left+1;
	            right = mid+1;
	        }
	    }
	    return false;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
  // } Driver Code Ends