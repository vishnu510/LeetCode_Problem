class Solution {
public:
    int nextGreaterElement(int n) {
        int num = n;
        vector<int> nums;
        while(num>0){
            nums.push_back(num%10);
            num/=10;
        }
        reverse(nums.begin(),nums.end());
        num = nums.size();
        int l,m;
        for(l=num-2;l>=0;l--){
            if(nums[l]<nums[l+1]) break;
        }
        if(l<0) return -1;
        else{
            for(m = num-1;m>l;m--){
                if(nums[m]>nums[l]) break;
            }
            swap(nums[m],nums[l]);
            reverse(nums.begin()+l+1,nums.end());
        }
        long long res = 0;
        for(int i=0;i<num;i++){
            res = res*10 + nums[i];
        }
        if(res>INT_MAX) return -1;
        return res;
    }
};