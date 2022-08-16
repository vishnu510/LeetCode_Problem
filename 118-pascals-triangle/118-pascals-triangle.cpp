class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> pascalTraingle(numRows);
        
        for(int i=0;i<numRows;i++){
            
            pascalTraingle[i].resize(i+1);
            
            pascalTraingle[i][0] = pascalTraingle[i][i] = 1;
            
            for(int j =1; j < i; j++){
                
                pascalTraingle[i][j] = pascalTraingle[i-1][j-1] + pascalTraingle[i-1][j];
            }
        }
        return pascalTraingle;
    }
};