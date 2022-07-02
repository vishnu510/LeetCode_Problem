// { Driver Code Starts
// C++ program Find concatenated string with 
// uncommon characters of given strings 
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


class Solution
{
    public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) 
    { 
        // Your code here
        int n1 = s1.size(),n2 = s2.size();
        unordered_map<char,int> ump;
        for(int i=0;i<n1;i++){
            ump[s1[i]]++;
        }
        string ans ="";
        for(int i=0;i<n2;i++){
            if(ump.find(s2[i])!=ump.end()){
                ump[s2[i]] = -1;
            }
        }
        for(int i=0;i<n1;i++){
            if(ump[s1[i]]!=-1){
                ans+=s1[i];
            }
        }
        for(int i=0;i<n2;i++){
            if(ump.find(s2[i])==ump.end()){
                ans+=s2[i];
            }
        }
        if(ans.size()==0){
            ans = "-1";
        }
        return ans;
    }

};

// { Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
	int t;
	cin >> t;
	
	while(t--){
    	string s1, s2;
    	cin >> s1 >> s2;
    	Solution obj;
    	string res = obj.concatenatedString(s1, s2);
    	cout<<res<<endl;
	}
	return 0; 
}
  // } Driver Code Ends