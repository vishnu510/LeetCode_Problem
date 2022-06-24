// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxBalls(int n, int m, vector<int> a, vector<int> b){
        // code here
        int i=0,j=0;
        int s1=0,s2=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        while(i<n || j<m){
            if(i<n && j<m){
                if(a[i]<b[j]){
                    s1 += a[i];
                    i++;
                }
                else if(a[i]>b[j]){
                    s2 += b[j];
                    j++;
                }
                else {
                    int x = a[i];
                    int c1 = 0,c2 = 0;
                    while(a[i++]==x)c1++;
                    while(b[j++]==x)c2++;
                    i--,j--;
                    
                    if(s1>s2){
                        s2 = s1 + (c1+c2-1)*x;
                        if(c1>1)s1 += (c1+c2-2)*x;
                        else s1 += x;
                    }
                    else{
                        s1 = s2 + (c1 + c2 -1)*x;
                        if(c2>1)s2 += (c1+c2-2)*x;
                        else s2 += x;
                    }
                }
            }
            else if(i<n){
                s1 += a[i];
                i++;
            }
            else if(j<m){
                s2 += b[j];
                j++;
            }
        }
        return max(s1,s2);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        vector<int> a(N), b(M);
        for(int i = 0;i < N;i++)
            cin>>a[i];
        for(int i = 0;i < M;i++)
            cin>>b[i];
        
        Solution ob;
        cout<<ob.maxBalls(N, M, a, b)<<"\n";
    }
    return 0;
}  // } Driver Code Ends