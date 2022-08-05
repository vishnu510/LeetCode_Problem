class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
    int j=0;

    int sum =0,count = 0;
    
    unordered_map<int,int> ump;

    for (;j<n;j++)
    {
        sum += nums[j];

        if(sum==k){
            count++;
        }

        if(ump.find(sum-k)!=ump.end()){
            count += ump[sum-k];
        }
        ump[sum]++;
    }
    return count;
    }
};