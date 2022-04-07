class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int size = nums.size();
        
        int count =0;
        for(int i=0;i<size;i++){
            int count1 =0,numb = nums[i];
            while(numb){
                numb = numb/10;
                count1++;
            }
            if(count1%2==0){
                count++;
            }
        }
        return count;
    }
};