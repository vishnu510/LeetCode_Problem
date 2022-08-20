class Solution {
public:
    
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size(), col = matrix[0].size();
        
        int left =0, right = row*col -1, mid;
        
        while( left <= right){
            
            mid = (left+right)/2;
            
            if(matrix[mid/col][mid%col]==target){
                return true;
            }
            
            if(matrix[mid/col][mid%col] < target){
                
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return false;
    }
};