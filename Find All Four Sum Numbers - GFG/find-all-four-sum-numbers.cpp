// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        // Your code goes here
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int rem=target-(nums[i]+nums[j]);
                int p1=j+1,p2=nums.size()-1;
                while(p1<p2){
                    //int sum=nums[p1]+nums[p2];
                    vector<int>temp;
                    if(nums[p1]+nums[p2]<rem)
                        p1++;
                    else if(nums[p1]+nums[p2]>rem)
                        p2--;
                    else{
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[p1]);
                        temp.push_back(nums[p2]);
                        ans.push_back(temp);
                        if(nums[p1]==nums[p2])
                            break;
                        else{
                            int x=nums[p1],y=nums[p2];
                            while(nums[p1]==x)p1++;
                            while(nums[p2]==y)p2--;
                        }
                    }
                }
                    
                }
            }
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends