// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
     void solve(int open,int close,string op,vector<string> &ans)
   {
       if(!open && !close)
       {
           ans.push_back(op);
           return;
       }
       if(open==close)
       {
           string op1=op;
           op1.push_back('(');
           open--;
           solve(open,close,op1,ans);
       }
       else if(!open && close)
       {
           string op1=op;
           op1.push_back(')');
           close--;
           solve(open,close,op1,ans);
       }
       else
       {
          string op1=op;
          string op2=op;
          
          int open1=open;
          int close1=close;
          
          op1.push_back('(');
          open1--;
          op2.push_back(')');
          close1--;
           
          solve(open1,close,op1,ans);
          solve(open,close1,op2,ans);
       }
       
       return;
   }

    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        if(n==0) return ans;
        string str = "";
        solve(n,n,str,ans);
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends