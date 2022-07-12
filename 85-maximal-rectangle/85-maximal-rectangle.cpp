class Solution {
public:
    
    int largestArea(vector<int> & histogram){
        int n =histogram.size(),area;
        stack<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty() && histogram[stk.top()]>=histogram[i]){
            int top = stk.top();
            stk.pop();
            int start;
            
            if(stk.empty()){
                start =-1;
            }
            else{
                start =stk.top();
            }
            int currArea = histogram[top]*(i-start-1);
            area = max(area,currArea);
        }
            stk.push(i);
        }
        
        while(!stk.empty()){
            int top = stk.top();
            stk.pop();
            int start;
            
            if(stk.empty()){
                start =-1;
            }
            else{
                start =stk.top();
            }
            int currArea = histogram[top]*(n-start-1);
            area = max(area,currArea);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m==0){
            return 0;
        }
        int n=matrix[0].size(),result =0;
        vector<int> histogram(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                 histogram[j]+=1;   
                }
                else{
                    histogram[j] =0;
                }
            }
            result = max(result,largestArea(histogram));
        }
        return result;
    }
};