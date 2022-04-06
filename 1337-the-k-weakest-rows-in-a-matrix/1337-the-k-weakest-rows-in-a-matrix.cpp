class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size();
    int col = mat[0].size();
   
    vector<pair<int,int>> res(row);
        vector<int> result(k);

        for(int i = 0;i<row;i++){
             int count=0;
            for(int j=0;j<col;j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            res[i] = make_pair(count,i);
        }
        sort(res.begin(),res.end());
        for(int i=0;i<k;i++){
            result[i] = res[i].second;
        }
        return result;
    }
};