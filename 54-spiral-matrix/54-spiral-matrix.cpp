class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    vector<int> v;
        
    int row=0,col=0;
    while(row< r && col <c)
    {   
        
        if(row+1 == r)
        {
            for(int i=col;i<c;i++)
            v.push_back(matrix[row][i]);
            break;
        }
        if(col+1 == c)
        {
            for(int i=row;i<r;i++)
            v.push_back(matrix[i][col]);
            break;
        }
        
        
        int i;
        for(i=col;i<c;i++)
        v.push_back(matrix[row][i]);
        
        row++;
        
        for( i=row;i<r;i++)
        v.push_back(matrix[i][c-1]);
        
        c--;
        
        for(i=c-1;i>=col;i--)
        v.push_back(matrix[r-1][i]);
        
        r--;
        
        for(i=r-1;i>=row;i--)
        v.push_back(matrix[i][col]);
        
        col++;
    }
   
   
    
    return v;
    }
};