class Solution {
public:
    void solution(int row,int n,vector<bool>&cols, vector<bool>&leftDiag,vector<bool>&rightDiag,vector<string>&temp,vector<vector<string>>&ans){
    if(row==n){
        ans.push_back(temp);
        return;
    }
    string str(n,'.');
    // its check all column for current row
    for(int col=0;col<n;col++){
        // if current cell is safe then we can place the queen
        if(cols[col]==false and leftDiag[row+col]==false and rightDiag[row-col+n-1]==false){
            cols[col] = true;
            leftDiag[row+col] = true;
            rightDiag[row-col+n-1] = true;
            str[col] = 'Q';
            temp.push_back(str);
            solution(row+1,n,cols,leftDiag,rightDiag,temp,ans);
            // if we didn't get right place backrack
            temp.pop_back();
            str[col] = '.';
            //we have remove our queen from that position the release all the bloacked cell
            cols[col]  = false;
            leftDiag[row+col] = false;
            rightDiag[row-col+n-1] = false;
        }
    }
    
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> temp;
    vector<bool> cols(n,false); //to track bloacked column
    vector<bool> leftDiag(2*n+1,false); //to track bloacked left diagonals 
    vector<bool> rightDiag(2*n+1,false); //to track bloacked right diagonals
    solution(0,n,cols,leftDiag,rightDiag,temp,ans);
    return ans;
}
};