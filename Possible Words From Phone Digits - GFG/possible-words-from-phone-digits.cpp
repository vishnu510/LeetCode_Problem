// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    unordered_map<int,string> m;
    vector<string> res;
    void helper(int i,int n,int a[],string &ans){
        if(i==n){
            res.push_back(ans);
            return;
        }
        else{
            string temp  = m[a[i]];
            for(int j=0;j<temp.size();j++){
                ans.push_back(temp[j]);
                helper(i+1,n,a,ans);
                ans.pop_back();
            }
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        string ans;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        helper(0,n,a,ans);
        sort(res.begin(),res.end());
        return res;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends