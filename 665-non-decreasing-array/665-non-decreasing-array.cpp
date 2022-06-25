class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int violation = 0;
        for(int i=1;i<nums.size();i++){
            // case for violation
            if(nums[i-1] > nums[i]){
                if(violation == 1){
                    return false;
                }
                //if no prev violation, then violation++
                violation++;
               
                // fixing violation => operation 1
                if(i<2 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                // fixing violation => operation 2
                else
                    nums[i] = nums[i-1];
                
            }
        }
        
        return true;
    }
};