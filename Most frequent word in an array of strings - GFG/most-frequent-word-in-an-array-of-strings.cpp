// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        string s;
        int mx =-1;
        for(auto i:mp){
            if(i.second >=mx){
                mx = i.second;
                s = i.first;
            }
        }
        set<string> st;
        for(auto i:mp){
            if(i.second==mx)
            st.insert(i.first);
        }
        map<string,int> mp2;
        for(int i=(n-1);i>=0;i--){
            if(st.find(arr[i])!=st.end()){
                mp2[arr[i]]=i;
            }
        }
        string ans;
        int mxx = -1;
        for(auto i:mp2){
            if(i.second > mxx){
                mxx  = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends