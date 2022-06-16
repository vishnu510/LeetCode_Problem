// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define lli long long int
class Solution{
public:
    long long int optimalKeys(int N){
        // code here
        if(N<6){
            return N;
        }
        lli screenSize[N+1],scp,scpp,scppp;
        screenSize[0] = 0;
        for(int i=1;i<=6;i++){
            screenSize[i] = i;
        }
        for(int i=7;i<=N;i++){
            scp = 2*screenSize[i-3];
            scpp = 3*screenSize[i-4];
            scppp = 4*screenSize[i-5];
            screenSize[i] = max({scp,scpp,scppp});
        }
        return screenSize[N];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends