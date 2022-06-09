// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
        int n = s.length();
        if(n<2){
            return s;
        }
        int maxLen=0,start=0;
        int low,high;
        for(int i=0;i<n;i++){
            low = i-1;
            high = i+1;
            while(high<n && s[high]==s[i]){
                high++;
            }
            while(low>=0 && s[low]==s[i]){
                low--;
            }
            while(low>=0 && high<n && s[low]==s[high]){
                high++; low--;
            }
            int length = high-low-1;
            if(maxLen<length){
                maxLen = length;
                start = low+1;
            }
        }
        return s.substr(start,maxLen);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends