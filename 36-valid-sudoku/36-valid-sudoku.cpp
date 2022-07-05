class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row(9),cols(9),block(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                if(board[i][j]=='.') continue;
                int curr = board[i][j]-'0';
                
                if(row[i].count(curr)||cols[j].count(curr)||block[(i/3)*3+j/3].count(curr)){
                    return false;
                }
                row[i].insert(curr);
                cols[j].insert(curr);
                block[(i/3)*3+j/3].insert(curr);
            }
        }
        return true;
    }
};