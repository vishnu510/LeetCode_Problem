class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> temp;
        
        int m = mat.size(), n = mat[0].size();
        
        for(int r = 0;r<m;r++){
            temp.clear();
            for(int j =0,i =r;j<n && i<m;i++,j++){
                temp.push_back(mat[i][j]);
            }
            sort(temp.begin(),temp.end());
            
            for(int j=0,i=r;j<n && i<m;i++,j++){
                mat[i][j] = temp[j];
            }
        }
        
        for(int c=1;c<n;c++){
            temp.clear();
            
            for(int i =0,j=c; j<n && i<m;i++,j++){
                temp.push_back(mat[i][j]);
            }
            sort(temp.begin(),temp.end());
            for(int i =0,j=c; j<n && i<m;i++,j++){
                mat[i][j] = temp[i];
            }
        }
        return mat;
    }
};