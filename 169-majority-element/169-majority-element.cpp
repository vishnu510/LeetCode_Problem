class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major =nums[0],count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count++;
                major = nums[i];
            }
            else if(major==nums[i]){
                count++;
                major = nums[i];
            }
            else
                count--;
        }
        return major;
     
    }
};