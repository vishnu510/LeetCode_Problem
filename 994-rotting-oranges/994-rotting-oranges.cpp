class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int row = grid.size();
       int col = grid[0].size();
       vector<int> direction = {-1,0,1,0,-1};
       queue<pair<int,int>> que;
       int freshOrange = 0;
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(grid[i][j]==2){
                   que.push({i,j});
               }
               if(grid[i][j]==1){
                   freshOrange++;
               }
           }
       }
       int timeTaken = -1;
        while(!que.empty()){
            int queSize = que.size();
            while(queSize--){
                pair<int,int> pair = que.front();
                que.pop();
                for(int i=0;i<4;i++){
                    int r = pair.first + direction[i];
                    int c = pair.second + direction[i+1];
                    if(r>=0 && r<row && c>=0 && c<col && grid[r][c]==1){
                        grid[r][c]=2;
                        que.push({r,c});
                        freshOrange--;
                    }
                }
            }
            timeTaken++;
        }
        if(freshOrange>0) return -1;
        if(timeTaken == -1) return 0;
        return timeTaken;
    }
};