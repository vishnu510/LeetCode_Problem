class Solution {
public:
     int totalHammingDistance(vector<int>& nums) {
         int result =0;
         for(int i=0;i<32;i++){
             int count =0;
             for(int j=0;j<nums.size();j++){
                 if(nums[j] & (1<<i)){
                     count++;
                 }
             }
             result+=(count*(nums.size()-count));
         }
         return result;
     }
};