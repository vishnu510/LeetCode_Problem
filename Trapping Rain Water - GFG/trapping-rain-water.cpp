// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<long long> left(n,0),right(n,0);
        long long ans = 0;
        int l = arr[0],m = arr[n-1];
        for(int i=0;i<n;i++){
            left[i] = max(l,arr[i]);
            l = max(l,arr[i]);
        }
        for(int i=n-1;i>=0;i--){
            right[i] = max(m,arr[i]);
            m = max(m,arr[i]);
        }
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-arr[i];
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends