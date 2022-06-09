// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        string res1 = "";
        for(int i=2;i<str1.size();i++){
            res1+=str1[i];
        }
        res1+=str1[0];
        res1+=str1[1];
        if(res1 == str2){
            return true;
        }
        string res2 = "";
        for(int i=2;i<str2.size();i++){
            res2+=str2[i];
        }
        res2+=str2[0];
        res2+=str2[1];
        if(res2 == str1){
            return true;
        }
        return false;
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends