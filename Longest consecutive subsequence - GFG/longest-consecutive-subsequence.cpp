// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int count=0,last=0,result =0;
      unordered_map<int,int> ump;
      for(int i=0;i<N;i++){
          ump[arr[i]]++;
      }
      for(int i=0;i<N;i++){
          last = max(arr[i],last);
      }
      for(int i=1;i<=last+1;i++){
          if(ump[i]){
              count++;
          }
          else{
              result = max(result,count);
              count =0;
          }
      }
      return result;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends