// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
   
   bool isSafe(int r,int j,int n,vector<int> & temp){
       for(auto it:temp){
           if(it==j){
               return false;
           }
       }
       for(int i=0;i<temp.size();i++){
           if(r-i-1==abs(j-temp[i])){
               return false;
           }
       }
       return true;
   }
   void solve(int r,int n,vector<int> & temp,vector<vector<int>>& ans){
       if(r>n){
           ans.push_back(temp);
           return;
       }
       for(int c=1;c<=n;c++){
           if(isSafe(r,c,n,temp)){
               temp.push_back(c);
               solve(r+1,n,temp,ans);
               temp.pop_back();
           }
       }
   }
   
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1,n,temp,ans);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends