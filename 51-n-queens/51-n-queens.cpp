class Solution {
public:
    void helper(int row,int n,vector<bool>& cols,vector<bool>&ld,vector<bool>&rd,vector<vector<string>>& ans,vector<string>& temp){
        if(row == n){
            ans.push_back(temp);
            return;
        }
        string str(n,'.');
        
        for(int col =0;col<n;col++){
            if(cols[col]==false && ld[row+col]==false && rd[row-col +n-1]==false){
                cols[col] = true;
                ld[row+col] = true;
                rd[row-col+n-1] = true;
                str[col] = 'Q';
                temp.push_back(str);
                helper(row+1,n,cols,ld,rd,ans,temp);
                temp.pop_back();
                str[col] = '.';
                cols[col] = false;
                ld[row+col] = false;
                rd[row-col+n-1] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        vector<bool> cols(n,false);
        vector<bool> ld(2*n+1,false);
        vector<bool> rd(2*n+1,false);
        helper(0,n,cols,ld,rd,ans,temp);
        return ans;
    }
};