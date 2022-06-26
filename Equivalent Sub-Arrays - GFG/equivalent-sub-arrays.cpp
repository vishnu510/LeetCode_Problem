// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)  mp[arr[i]] = 0;
        int disc = mp.size(),i=0,j=0,ans = 0,cc=0; 
        while(j<n)
        {
            while(cc<disc && j<n)
            {
                if(mp[arr[j]] == 0)  mp[arr[j]]++,cc++;
                else mp[arr[j]]++;
                j++;
            }
            while(cc==disc)
            {
                ans+= n-j+1;
                mp[arr[i]]--;
                if(mp[arr[i]]==0)    cc--;
                i++;
            }
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends