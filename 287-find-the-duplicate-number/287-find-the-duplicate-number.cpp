class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(auto i:nums){
            mp[i]++;
        }
        
        int res =0;
        for(auto it:mp){
            
            if(it.second>1){
                res = it.first;
                break;
            }
        }
        return res;
    }
};