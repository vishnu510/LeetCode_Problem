class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        int ans=INT_MAX;
        int j=-1,i=0,sum=0;
        while(i<2*n){
           sum+=nums[i];
           if((i-j)<=n && sum==x && (j<0 || (j<n && i>=n-1))){
               ans=min(ans,i-j);
           }
           else if(sum>x){
             while(sum>x) sum-=nums[++j];
           }
           else if((i-j)>n) sum-=nums[++j];
           if(sum==x && (j<0 || (j<n-1 && i>=n-1))) ans=min(ans,i-j);
           i++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};