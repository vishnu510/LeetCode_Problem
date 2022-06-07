class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count= 0,j;
        for(int i=0;i<nums.size();i++){
            j = i+1;
            while(j!=nums.size()){
                if(nums[i]==nums[j++] && i<j){
                count++;
            }
            }
            
        }
        return count;
    }
};