// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long start =1,end =1,ans =INT_MIN;
	    int i=0,j=n-1;
	    
	    while(i<n && j>=0){
	        
	        start*= arr[i];
	        end*= arr[j];
	        ans = max(ans,max(start,end));
	        if(arr[i]==0){
	            start =1;
	        }
	        if(arr[j]==0){
	            end =1;
	        }
	        i++;
	        j--;
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends