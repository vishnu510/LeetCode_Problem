class Solution {
public:
    vector<int>res;
    vector<int> decompressRLElist(vector<int>& nums) {
        if(nums.size()==0) return nums;
        int rep=0;
        for(int i=0;i<nums.size();i+=2){
             rep= nums[i];
            while(rep--){
                res.push_back(nums[i+1]);
            }
        }
        return res;
    }
};