class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c,int nr,int nc){
    grid[r][c] = '0';
    if(r-1>=0 && grid[r-1][c]=='1'){
        dfs(grid,r-1,c,nr,nc);
    }
    if(r+1<nr && grid[r+1][c]=='1'){
        dfs(grid,r+1,c,nr,nc);
    }
    if(c-1>=0 && grid[r][c-1]=='1'){
        dfs(grid,r,c-1,nr,nc);
    }
    if(c+1<nc && grid[r][c+1]=='1'){
        dfs(grid,r,c+1,nr,nc);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    int numOfIsland = 0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]=='1'){
                dfs(grid,i,j,row,col);
                numOfIsland++;
            }
        }
    }
    return numOfIsland;  
    }
};