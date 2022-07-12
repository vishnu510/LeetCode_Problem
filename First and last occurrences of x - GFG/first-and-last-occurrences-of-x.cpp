// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    long count=0;
    vector<long long>ans;
  for(long long i=0;i<n;i++){
      if(arr[i]==x){
          ans.push_back(i);
          count++;
      }
  }
  if(ans.size()==0){
      return {-1,-1};
  }
   return {ans[0],ans[count-1]};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends