class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem = sum%k;
            if(rem ==0 && i>0){
                return true;
            }
            if(ump.find(rem)==ump.end()){
                ump[rem] =i;
            }
            else if(i-ump[rem]>=2){
                return true;
            }
        }
        return false;
    }
};