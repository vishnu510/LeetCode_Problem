class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size(), m= matrix[0].size();
        
        for(int i=0;i<n;i++){
            
            for(int j=1;j<m;j++){
                
                matrix[i][j] = matrix[i][j] + matrix[i][j-1];
            }
        }
        
        int count =0,sum;
        unordered_map<int,int> mp;
        for(int colstart =0;colstart<m;colstart++){
            
            for(int col = colstart;col<m;col++){
                mp.clear();
                mp[0] = 1;
                sum =0;
                for(int row = 0;row<n;row++){
                    
                    sum+= matrix[row][col]-(colstart>0?matrix[row][colstart-1]:0);
                    count+=(mp.find(sum-target)!=mp.end()?mp[sum-target]:0);
                    mp[sum]++;
                }
            }
        }
        return count;
    }
};