// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int n = str.size();
        int i=0;
        long long int num = 0;
        if(str[0]=='-'){
            i=1;
        }
        for(;i<n;i++){
            if(str[i]>='0' && str[i]<='9'){
                num = num*10 + (str[i]-'0');
            }
            else{
                return -1;
            }
        }
        if(str[0]=='-'){
            return num*-1;
        }
        return num;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends