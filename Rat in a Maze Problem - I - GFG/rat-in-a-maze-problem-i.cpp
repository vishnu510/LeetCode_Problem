// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
   int size;
   int dx[4]={1,-1,0,0};
   int dy[4]={0,0,1,-1};
   char c[4]={'D','U','R','L'};
   void solve(int i,int j,vector<vector<int>> &m,string &s){
       if(i==size-1 && j==size-1){
           ans.push_back(s);
           return;
       }
       m[i][j]=0;
       for(int p=0;p<4;p++){
           int a=i+dx[p];
           int b=j+dy[p];
           if(a>=0 && b>=0 && a<size && b<size && m[a][b]==1){
               s=s+c[p];
               solve(a,b,m,s);
               s=s.substr(0,s.length()-1);
           }
       }
       m[i][j]=1;
       
   }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        ans.clear();
        size =n;
        if(m[0][0]==0 ||m[n-1][n-1]==0)return ans;
       string s="";
       solve(0,0,m,s);
       return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends