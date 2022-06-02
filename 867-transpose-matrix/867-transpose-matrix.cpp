class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int temp;
        vector<vector<int>> transMat(matrix[0].size(),vector<int>(matrix.size(),0));
        for(int i =0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                transMat [j][i] = matrix[i][j];
            }
        }
        return transMat;
    }
};