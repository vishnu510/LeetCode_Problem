class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> postive,negative,ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                negative.push_back(nums[i]);
            }
            else{
                postive.push_back(nums[i]);
            }
        }
        int n = postive.size();
        int i=0;
            while(i<n){
                ans.push_back(postive[i]);
                ans.push_back(negative[i]);
                i++;
            }
        return ans;
    }
};