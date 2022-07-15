// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int sum1 =0,sum2 =0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                sum1+=arr[i];
                if(sum1>sum2){
                    sum1 = sum1;
                }
                else{
                    sum1 = sum2;
                }
            }
            else{
                sum2+=arr[i];
                if(sum2>sum1){
                    sum2 = sum2;
                    
                }
                else{
                    sum2 = sum1;
                }
            }
        }
        return sum1>sum2?sum1:sum2;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends