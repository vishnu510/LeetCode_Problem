// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int maxSum = 0;
        int maxIndex =0;
        unordered_map<int,int> mp;
        for(int i=0;i<A.size();i++){
          maxSum+=A[i];
          if(maxSum==0){
              maxIndex = i+1;
          }
          else if(mp.find(maxSum)!=mp.end()){
              maxIndex = max(maxIndex,i-mp[maxSum]);
          }
          else{
              mp[maxSum] = i;
          }
        }
        return maxIndex;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends