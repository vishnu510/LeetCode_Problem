class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int wish = INT_MAX, wish1 =INT_MAX;
        
        for(int vish : nums){
            
            if(vish <= wish){
                wish = vish;;
            }
            else if (vish<=wish1){
                wish1 = vish;
            }
            else{
                return true;
            }
        }
        return false;
    }
};