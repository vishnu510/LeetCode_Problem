struct node{
    int x,y,time;
    
    node(int _x,int _y,int _time){
        
        x = _x;
        y = _y;
        time = _time;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       
        int n = grid.size();
        int m = grid[0].size();
        
        queue<node> q;
        int countOrange =0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==2){
                    q.push(node(i,j,0));
                }
                if(grid[i][j]!=0){
                    countOrange++;
                }
            }
        }
        
        int ans =0,count =0;
        
        while(!q.empty()){
            
            int x = q.front().x;
            int y = q.front().y;
            int time  = q.front().time;
            
            q.pop();
            
            ans = max(ans,time);
            count++;
            
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            
            for(int i=0;i<4;i++){
                
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY]==1){
                    grid[newX][newY] = 2;
                    q.push(node(newX,newY,time+1));
                }
            }
        }
        if(count==countOrange) return ans;
        return -1;
    }
};