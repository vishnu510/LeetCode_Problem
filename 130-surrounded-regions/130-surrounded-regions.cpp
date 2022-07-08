class Solution {
public:
    
    bool isSafe(int i,int j, int m,int n){
        
        return (i>=0 && i<m && j>=0 && j<n);
    }
    
    bool isBorder(int i,int j,int m,int n){
        
        return (i==0 || i==m-1 || j==0 || j==n-1);
    }
    
    void solve(vector<vector<char>>& board) {
        
        if(board.size()==0){
            return;
        }
        queue<pair<int,int>> q;
        vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
        int m = board.size(),n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && isBorder(i,j,m,n)){
                    board[i][j] = '.';
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> f = q.front();
            q.pop();
            for(int i=0;i<dir.size();i++){
                int dx = f.first + dir[i].first;
                int dy = f.second + dir[i].second;
                if(isSafe(dx,dy,m,n) && !isBorder(dx,dy,m,n) && board[dx][dy]=='O'){
                    board[dx][dy] = '.';
                    q.push({dx,dy});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='.'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};