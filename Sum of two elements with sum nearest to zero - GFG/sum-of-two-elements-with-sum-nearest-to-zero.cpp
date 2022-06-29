// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int closestToZero(int arr[], int n)
        {
            // your code here
            int currSum =0,finalSum =INT_MAX,i=0,j=n-1;
            sort(arr,arr+n);
            while(i<j){
                currSum = arr[i]+arr[j];
                if(abs(currSum)<abs(finalSum)){
                    finalSum = currSum;
                }
                else if(abs(currSum)==abs(finalSum)){
                    finalSum = max(currSum,finalSum);
                }
                if(currSum>0){
                    j--;
                }
                else{
                    i++;
                }
            }
            return finalSum;
        }
};

// { Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends