class Solution {
public:
    
    int dp[200][200];
    int n,m,count;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        count =0;
        n = matrix.size();
        m = matrix[0].size();
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                count = max(count,solve(matrix,i,j,-1));
            }
        }
        return count;
    }
    
    int solve(vector<vector<int>>& mat,int i,int j, int prev){
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j]<=prev){
            return 0;
        }
        if(dp[i][j]) return dp[i][j];
        
        return dp[i][j] = 1+ max({solve(mat,i-1,j,mat[i][j]),
                                  solve(mat,i+1,j,mat[i][j]),
                                  solve(mat,i,j-1,mat[i][j]),
                                  solve(mat,i,j+1,mat[i][j])});
    }
};