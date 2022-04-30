class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long left_sum =0;
        for(auto c:nums){
            left_sum+=c;
        }
        int minimum = INT_MAX;
        int index = 0,diff;
        long long right_sum=0;
        for(int i=0;i<n;i++){
            left_sum-= nums[i];
            right_sum+= nums[i];
            long long left = right_sum/(i+1);
            long long right = i<n-1?left_sum/(n-i-1):0;
            diff = abs(left-right);
            
            if(diff<minimum){
                minimum = diff;
                index = i;
            }
        }
        return index;
    }
};