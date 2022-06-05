class Solution {
public:
    void moveZeroes(vector<int>& nums) {
     if(nums.size()<2) return;
    int countZero = 0;
    int index=0;
    
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            nums[index]=nums[i];
            index++;
        }
        else{
            countZero++;
        }
    }
        while (countZero--)
    {
        nums[index] = 0;
        index++;
    }
    return;
        
    }
};