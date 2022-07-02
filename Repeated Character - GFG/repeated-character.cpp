// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    char firstRep (string s)
    {
        //code here.
        unordered_map<char,int> ump;
        for(int i=0;i<s.size();i++){
            ump[s[i]]++;
        }
        for(int i =0;i<s.size();i++){
            if(ump.find(s[i])!=ump.end()){
                if(ump[s[i]]>1){
                    return s[i];
                }
            }
        }
        return '#';
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}


  // } Driver Code Ends