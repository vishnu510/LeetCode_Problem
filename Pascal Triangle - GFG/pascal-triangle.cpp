// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
class Solution{
public:
    const long long m = 1e9+7;
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<long long> v(n);
        vector<long long> pre(n);
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(j == 0 || j == i-1)
                v[j] = 1;
                else
                {
                   v[j] = (pre[j-1]%m + pre[j]%m)%m; 
                }
            }
            pre = v;
        }
        return (v);
    }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends