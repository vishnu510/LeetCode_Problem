// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            map<char,int> a,b,unique;
            string str ="",res ="";
            for(int i=0;i<A.size();i++){
                a[A[i]]++;
            }
            for(int i=0;i<B.size();i++){
                b[B[i]]++;
            }
            for(int i=0;i<A.size();i++){
                if(b[A[i]]==0) str+=A[i];
            }
            for(int i=0;i<B.size();i++){
                if(a[B[i]]==0) str+=B[i];
            }
            if(str=="") return "-1";
            sort(str.begin(),str.end());
            for(int i=0;i<str.size();i++){
                unique[str[i]]=1;
            }
            for(int i=0;i<str.size();i++){
                if(unique[str[i]]==1){
                    res+=str[i];
                    unique[str[i]]=0;
                }
            }
            return res;
        }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends