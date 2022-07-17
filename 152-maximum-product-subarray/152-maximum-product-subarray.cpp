class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int start =1,end =1,ans = INT_MIN,i=0,j = nums.size()-1;
        
        while(i<nums.size() && j>=0){
            
            start*= nums[i];
            end*= nums[j];
            
            ans = max(ans,max(start,end));
            
            if(nums[i]==0){
                start =1;
            }
            
            if(nums[j]==0){
                end =1;
            }
            i++;
            j--;
        }
        
        return ans;
    }
};