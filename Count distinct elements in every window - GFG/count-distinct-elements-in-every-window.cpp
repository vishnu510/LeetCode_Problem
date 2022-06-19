// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int> ans;
        map<int,int> counter;
        for(int i=0;i<k-1;i++){
            counter[A[i]]++;
        }
        for(int i=k-1;i<n;i++){
            counter[A[i]]++;
            ans.push_back(counter.size());
            counter[A[i-k+1]]--;
            if(counter[A[i-k+1]]==0){
                counter.erase(A[i-k+1]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends