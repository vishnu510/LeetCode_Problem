class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int idx1 =0,idx2 =0;
        
        int n = numbers.size();
        
        int left =0,right =n-1;
        
        while(left < right){
            
            int sum = numbers[left] + numbers[right];
            
            if(sum==target){
                idx1 = left+1;
                idx2 = right +1;
            }
            if(sum < target){
                left++;
            }
            else {
                right--;
                 }
        }
        return {idx1,idx2};
    }
};