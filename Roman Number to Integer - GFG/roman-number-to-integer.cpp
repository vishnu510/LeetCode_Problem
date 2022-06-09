// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        map<char, int> table;
        
        table.insert(pair<char, int>('I', 1));
        table.insert(pair<char, int>('V', 5));
        table.insert(pair<char, int>('X', 10));
        table.insert(pair<char, int>('L', 50));
        table.insert(pair<char, int>('C', 100));
        table.insert(pair<char, int>('D', 500));
        table.insert(pair<char, int>('M', 1000));
         int res = 0;
        
        for (int i = 0; i < s.length(); i++)  {
            
            if ((table[s[i+1]] > table[s[i]]) && (i < s.length()-1)) {
//                
                res += table[s[i+1]] - table[s[i]];
                i++;
                
            } else {
                res += table[s[i]];
            }
            
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends