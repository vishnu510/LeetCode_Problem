class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int breakingPoint = -1;
        
        for(int i = nums.size()-1; i >0; i--){
            
            if(nums[i] > nums[i-1]){
                breakingPoint = i-1;
                break;
            }
        }
        
        if(breakingPoint < 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(int i = nums.size()-1; i>=0; i--){
            
            if(nums[i] > nums[breakingPoint]){
            
            swap(nums[i],nums[breakingPoint]);
            
            reverse(nums.begin() + breakingPoint + 1, nums.end());
            
            break;
            }
        }
    }
};