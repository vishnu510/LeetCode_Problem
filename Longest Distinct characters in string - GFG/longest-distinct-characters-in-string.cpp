// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    int start = 0;
    int ans = 0;
    vector<int> lenstr(256,-1);
    for(int i=0;i<s.length();i++){
        start = max(start,lenstr[s[i]]+1);
        int end = i-start+1;
        ans = max(ans,end);
        lenstr[s[i]] = i;
    }
    return ans;
}