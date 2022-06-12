class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int cs = 0,cid = -1;
        bool mp[10001] = {false};
        
        for(int i=0;i<n;i++){
            cs += nums[i];
            if(!mp[nums[i]])
                mp[nums[i]] = true;
            else{
                cid ++;
                while(nums[cid]!=nums[i]){
                    cs -= nums[cid];
                    mp[nums[cid]] = false;
                    cid++;
                }
                cs -= nums[cid];
            }
            ans < cs ? ans = cs : ans = ans;
        }
        return ans;
    }
};