class Solution {
public:
    
bool solution(int index,int row,int col,vector<vector<char>>&board,string word){
    if(index==word.size()) {
        return true;
    }
    if(row<0 or col<0 or row>=board.size() or col>=board[0].size() or board[row][col]=='.'){
        return false;
    }
    if(board[row][col]!=word[index]){
        return false;
    }
    char temp = board[row][col];
    board[row][col] = '.';
    if(solution(index+1,row-1,col,board,word)||solution(index+1,row+1,col,board,word)||
       solution(index+1,row,col-1,board,word)||solution(index+1,row,col+1,board,word)){
       return true;
    }
    board[row][col] = temp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(solution(0,i,j,board,word)){
                return true;
            }
        }
    }
    return false;
}
};