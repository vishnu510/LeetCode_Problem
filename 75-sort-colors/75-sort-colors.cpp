class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int c1=0,c2=0,c3=0;
        
        for(auto i:nums){
            if(i==0) c1++;
            if(i==1) c2++;
            if(i==2) c3++;
        }
        nums.clear();
        while(c1--){
            nums.push_back(0);
        }
        while(c2--){
            nums.push_back(1);
        }
        while(c3--){
            nums.push_back(2);
        }
    }
};