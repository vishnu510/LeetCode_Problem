// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    vector<int> map(26);
	    for(auto c:s){
	        map[c-'a']++;
	    }
	    int f1=INT_MAX,f2=INT_MAX;
	    for(int i=0;i<26;i++){
	        if(map[i]){
	            int f = map[i];
	            if(f1==INT_MAX){
	                f1 = f;
	            }
	            else if(f!= f1 and f2==INT_MAX){
	                f2 =f;
	            }
	            else if(f!=f1 and f!=f2) return false;
	        }
	    }
	    if(f2==INT_MAX) return true;
	    return abs(f1-f2)<=1 or f1==1 or f2==1;
	}
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}


  // } Driver Code Ends