// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  void solve(int index, int dots, string s, string temp, vector<string>& ans){
       if(dots==4 && index==s.size()){
           ans.push_back(temp.substr(0, temp.length()-1));
           return;
       }
       if(dots>4 || (dots==4 && index<s.size())){
           return;
       }
       int j=index;
       string val = "";
       while(j<s.size() && j<index+3){
           val+= s[j];
           if(stoi(val)<256 && (j==index || s[index]!='0')){
               solve(j+1, dots+1, s, temp+val+".", ans);
           }
           j++;
       }
   }
    vector<string> genIp(string &s) {
        // Your code here
        string temp="";
       vector<string>ans;
       if(s.length() > 12){
           return ans;
       }
       solve(0, 0, s, temp, ans);
       return ans;
    }

};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}  // } Driver Code Ends