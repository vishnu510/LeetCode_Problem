// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void helper(string s,int i,set<string>& res){
	        if(i==s.size()){
	            res.insert(s);
	            return;
	        }
	        for(int k=i;k<s.size();k++){
	            swap(s[i],s[k]);
	            helper(s,i+1,res);
	            swap(s[i],s[k]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> res;
		    helper(S,0,res);
		    vector<string> ans;
		    for(auto it:res){
		        ans.push_back(it);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends