class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int count =0,curr =0,next=0;
        for(int i=0;i<n-1;i++){
            next = max(next,i+nums[i]);
            if(i==curr){
                curr = next;
                next =0;
                count++;
            }
        }
        return count;
    }
};