// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> ans;
    set<vector<int>> st;
    void sum(int id,int t,vector<int>& v,vector<int> &arr){
        if(t==0){
            st.insert(v);
            return;
        }
        for(int i=id;i<arr.size();i++){
            if(i>id && arr[i]==arr[i-1]) continue;
            if(arr[i]>t) break;
            if(arr[i]<=t){
                v.push_back(arr[i]);
                sum(i,t-arr[i],v,arr);
                v.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        int n = A.size();
        vector<int> v;
        sort(A.begin(),A.end());
        sum(0,B,v,A);
        for(auto it:st){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends