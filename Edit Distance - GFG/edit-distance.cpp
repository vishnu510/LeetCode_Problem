// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        for(int i=0;i<=s.size();i++){
            for(int j=0;j<=t.size();j++){
                if(i==0){
                    dp[i][j] =j;
                }
                else if(j==0){
                    dp[i][j]=i;
                }
                else{
                    if(s[i-1]==t[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else{
                        int add = dp[i][j-1];
                        int replace = dp[i-1][j-1];
                        int remove = dp[i-1][j];
                        dp[i][j] = 1 + min(remove,min(add,replace));
                    }
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends