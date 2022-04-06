class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<pair<int,int>> curr;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    curr.push_back({i,j});
                }
            }
        }
        for(int i=0;i<curr.size();i++){
            int m = curr[i].first;
            int n = curr[i].second;
            int r =0,c=0;
            while(r<row){
                matrix[r][n] = 0;
                r++;
            }
            while(c<col){
                matrix[m][c] = 0;
                c++;
            }
        }
        
    }
};