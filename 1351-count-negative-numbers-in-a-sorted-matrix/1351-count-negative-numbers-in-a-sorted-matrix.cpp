class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int column = grid[0].size();
        int count=0;
        int i=rows-1,j=0;
        while(i>=0 and j<column){
            if(grid[i][j]<0){
                count+=(column -j);
                i--;
            }
            else{
                j++;
            }
        }
        return count;
    }
};