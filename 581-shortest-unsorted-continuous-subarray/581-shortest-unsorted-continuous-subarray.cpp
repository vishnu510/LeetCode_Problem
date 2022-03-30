class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = nums.size(),end = 0;
        int len = nums.size();
      vector<int> nums1(nums);
        sort(nums1.begin(),nums1.end());
        for(int i=0; i<len; i++){
            
                if(nums[i]!=nums1[i]){
                    start = min(start,i);
                    end = max(end,i);
                }
        }
        if(end-start>=0){
            return (end-start+1);
        }
        else{
            return 0;
        }
        
    }
};