// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int bit = log2(n);
        int sum = 0;
        for(int i=0;i<=bit;i++){
            int power = pow(2,i);
            int divisor = power*2;
            int rem = (n+1)% divisor;
            if(rem-power > 0){
                sum+=  (((n+1)/(power*2))*power) + rem-power;
            }
            else{
                sum+=((n+1)/(power*2))*power;
            }
        }
        return sum;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends