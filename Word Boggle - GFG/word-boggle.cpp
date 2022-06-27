// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:

   bool DFS(vector<vector<char>> &board, string &word, int i, int j, int n,int k) {
      if(n == word.size()) return true; 
      if(i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[n]) return false;
      board[i][j] = '0';
      bool status =   DFS(board, word, i + 1, j, n + 1,k)||  
                      DFS(board, word, i, j + 1, n + 1,k)||
                      DFS(board, word, i - 1, j, n + 1,k)||  
                      DFS(board, word, i, j - 1, n + 1,k)||
                      DFS(board, word, i+1, j+1, n + 1,k)||
                      DFS(board, word, i+1, j-1, n + 1,k)||
                      DFS(board, word, i-1, j-1, n + 1,k)||
                      DFS(board, word, i-1, j+1, n + 1,k);
                      
      board[i][j] = word[n];

      return status;
   }
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& word) {
	    // Code here
	     unordered_set<string>st;
  
       for(int k=0;k<word.size();k++)
   {
      for(int i = 0; i < board.size(); i++){ 
          for(int j = 0; j < board[i].size(); j++) {
              if(board[i][j] == word[k][0]){
              if(DFS(board, word[k], i, j, 0,k)){
                 st.insert(word[k]);
                 
              }
            
             }
             
          }
          
      }
   } 
   vector<string>ans;
   for(auto it:st) {ans.push_back(it);
   }
      return ans; 
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends