class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = INT_MIN,mxSum =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mxSum+=nums[i];
            maxSum = max(maxSum,mxSum);
            if(mxSum<=0){
                mxSum =0;
            }
        }
        int minSum = INT_MAX,mnSum =0;
        for(int i=0;i<n;i++){
            mnSum+=nums[i];
            minSum = min(minSum,mnSum);
            if(mnSum>0){
                mnSum =0;
            }
        }
        
        return max(abs(maxSum),abs(minSum));
    }
};