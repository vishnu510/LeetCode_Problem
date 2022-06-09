// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    bool check(string s){
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                return true;
            }
        }
        return false;
    }
    string helper(string &s){
        if(s.length()<=1) return s;
        int i=0;
        while(i<s.length()){
            if(i+1<s.length() && s[i]==s[i+1]){
                int j=i;
                while(j+1<s.length() && s[j]==s[j+1]){
                    j++;
                }
                s.erase(s.begin()+i,s.begin()+j+1);
            }
            else{
                i++;
            }
        }
        if(check(s)) return helper(s);
        return s;
    }
    string rremove(string s){
        // code here
        if(s.length()==0) return "";
        return helper(s);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends